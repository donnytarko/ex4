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
#include <fstream>
using std::ifstream;

const int maxWordLength = 16;


Mtmchkin::Mtmchkin(const std::string &fileName) {
    ifstream file(fileName);
    if (!file) {
		std::cerr << "cannot open file " << fileName << std::endl;
        //leave main
    }
    char line[maxWordLength];
    while (file.getline(line, maxWordLength)) {
        if (line == "Gremlin") {
            m_cards.push(Gremlin());
        }
        if (line == "Dragon") {
            m_cards.push(Dragon());
        }
        if (line == "Witch") {
            m_cards.push(Witch());
        }
        if (line == "Treasure") {
            m_cards.push(Treasure());
        }
        if (line == "Well") {
            m_cards.push(Well());
        }
        if (line == "Barfight") {
            m_cards.push(Barfight());
        }
        if (line == "Mana") {
            m_cards.push(Mana());
        }
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
            m_players.push_back(Healer(name, playerClass));
        } else if (playerClass == "Ninja") {
            m_players.push_back(Ninja(name, playerClass));
        } else if (playerClass == "Warrior") {
            m_players.push_back(Warrior(name, playerClass));
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
