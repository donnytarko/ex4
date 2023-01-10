#include "Mtmchkin.h"
#include "Cards/Card.h"
#include "Players/Healer.h"
#include "Players/Ninja.h"
#include "Players/Warrior.h"
#include "Cards/Gremlin.h"
#include "Cards/Dragon.h"
#include "Cards/Witch.h"
#include "Cards/Treasure.h"
#include "Cards/Well.h"
#include "Cards/Barfight.h"
#include "Cards/Mana.h"
#include "utilities.h"
#include "Exception.h"
#include <fstream>
#include <string>

const int maxWordLength = 16;

Mtmchkin::Mtmchkin(const std::string &fileName) {
    std::ifstream file(fileName);
    if (!file) {
		throw DeckFileNotFound();
    }
    int lineNumber = 1;
    char line[maxWordLength];
    while (file.getline(line, maxWordLength)) {
        if (strcmp(line, "Gremlin") == 0) {
            m_cards.push(Gremlin());
        }
        if (strcmp(line, "Dragon") == 0) {
            m_cards.push(Dragon());
        }
        if (strcmp(line, "Witch") == 0) {
            m_cards.push(Witch());
        }
        if (strcmp(line, "Treasure") == 0) {
            m_cards.push(Treasure());
        }
        if (strcmp(line, "Well") == 0) {
            m_cards.push(Well());
        }
        if (strcmp(line, "Barfight") == 0) {
            m_cards.push(Barfight());
        }
        if (strcmp(line, "Mana") == 0) {
            m_cards.push(Mana());
        }
        else {
            throw DeckFileFormatError(lineNumber);
        }
        lineNumber++;
    }
    if (lineNumber < 6) {
        throw DeckFileInvalidSize();
    }
    
    printStartGameMessage();
    printEnterTeamSizeMessage();
    std::cin >> m_numOfPlayers;
    if (m_numOfPlayers > 6 || m_numOfPlayers < 2) {
        printInvalidTeamSize();
    }
    printInsertPlayerMessage();
    
    std::string name;
    std::string playerClass;
    for (int i = 0; i < m_numOfPlayers; i++) {
        std::cin >> name;
        std::cin >> playerClass;
        if (playerClass == "Healer") {
            m_players.push_back(Healer(name));
        } else if (playerClass == "Ninja") {
            m_players.push_back(Ninja(name));
        } else if (playerClass == "Warrior") {
            m_players.push_back(Warrior(name));
        } else {
            std::cerr << "invalid player class" << std::endl;
        }
    }

    m_roundCount = 0;
    m_winnersCount = 0;
    m_losersCount = 0;
}


void Mtmchkin::playRound() {
    printRoundStartMessage(m_roundCount);
    for (Player player : m_players) {
        if (player.getPlace() == notPlaced) {
            printTurnStartMessage(player.getName());
            Card currentCard = m_cards.front();
            std::cout << "encounter with " << player.getJob() <<std::endl;
            currentCard.applyEncounter(player);
            m_cards.pop();
            m_cards.push(currentCard);
            if (isGameOver()) {
                printGameEndMessage();
            }
            if (player.getLevel() >= 10) {
                player.place(++m_winnersCount);
            }
            if (player.isKnockedOut()) {
                player.place(--m_losersCount);
            }
        }
    }
    m_roundCount ++;
}


int Mtmchkin::getNumberOfRounds() const {
    return m_roundCount;
}

void Mtmchkin::printLeaderBoard() const {
    printLeaderBoardStartMessage();
    for (int i = 1; i <= m_winnersCount; i++) {
        for (Player player : m_players) {
            if (player.getPlace() == i) {
                printPlayerLeaderBoard(player.getPlace(), player);
                printPlayerDetails(std::cout, player.getName(), 
                                    player.getJob(), player.getLevel(), 
                                    player.getForce(), player.getHealth(),
                                    player.getCoins());
            }
        }
    }
    int currentPlace = m_winnersCount;
    for (Player player : m_players) {
        if (player.getPlace() == notPlaced) {
            printPlayerLeaderBoard(++currentPlace, player);
            printPlayerDetails(std::cout, player.getName(), 
                                player.getJob(), player.getLevel(), 
                                player.getForce(), player.getHealth(),
                                player.getCoins());
        }
    }
    for (; currentPlace >= m_numOfPlayers; currentPlace++) {
        for (Player player : m_players) {
            if (player.getPlace() == currentPlace) {
                printPlayerLeaderBoard(currentPlace, player);
                printPlayerDetails(std::cout, player.getName(), 
                                    player.getJob(), player.getLevel(), 
                                    player.getForce(), player.getHealth(),
                                    player.getCoins());
            }
        }
    }
}



bool Mtmchkin::isGameOver() const{
    return (m_losersCount == m_numOfPlayers || m_winnersCount == m_numOfPlayers);
}
