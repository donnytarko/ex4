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
#include <iostream>
using std::cout;

const int maxWordLength = 16;

Mtmchkin::Mtmchkin(const std::string &fileName) {
    std::ifstream file(fileName);
    if (!file) {
		throw DeckFileNotFound();
    }
    int lineNumber = 0;
    std::string line;
    while (std::getline(file, line)) {
        lineNumber++;
        if (line.compare("Gremlin") == 0) {
            m_cards.push(new Gremlin());
        }
        else if (line.compare("Dragon") == 0) {
            m_cards.push(new Dragon());
        }
        else if (line.compare("Witch") == 0) {
            m_cards.push(new Witch());
        }
        else if (line.compare("Treasure") == 0) {
            m_cards.push(new Treasure());
        }
        else if (line.compare("Well") == 0) {
            m_cards.push(new Well());
        }
        else if (line.compare("Barfight") == 0) {
            m_cards.push(new Barfight());
        }
        else if (line.compare("Mana") == 0) {
            m_cards.push(new Mana());
        }
        else {
            throw DeckFileFormatError(lineNumber);
        }
    }
    if (lineNumber < 5) {
        throw DeckFileInvalidSize();
    }

    printStartGameMessage();
    printEnterTeamSizeMessage();

    std::cin >> m_numOfPlayers;

    if (m_numOfPlayers > 6 || m_numOfPlayers < 2) {
        printInvalidTeamSize();
    }
    
    std::string name;
    std::string playerClass;
    for (int i = 0; i < m_numOfPlayers; i++) {
        printInsertPlayerMessage();
        std::cin >> name;
        while (name.length() > 15) {
            printInvalidName();
            std::cin >> name;
        }
        std::cin >> playerClass;
        if (playerClass == "Healer") {
            m_players.push_back(new Healer(name));
        } else if (playerClass == "Ninja") {
            m_players.push_back(new Ninja(name));
        } else if (playerClass == "Warrior") {
            m_players.push_back(new Warrior(name));
        } else {
            printInvalidClass();
            i--;
        }
    }

    m_roundCount = 0;
    m_winnersCount = 0;
    m_losersCount = 0;
}


void Mtmchkin::playRound() {
    m_roundCount ++;
    printRoundStartMessage(m_roundCount);
    for (Player* player : m_players) {
        if (player->getPlace() == notPlaced) {
            printTurnStartMessage(player->getName());
            m_cards.front()->applyEncounter(*player);
            m_cards.push(m_cards.front());
            m_cards.pop();
            if (player->getLevel() >= 10) {
                player->place(++m_winnersCount);
            }
            if (player->isKnockedOut()) {
                player->place(m_numOfPlayers - m_losersCount);
                m_losersCount++;
            }
            if (isGameOver()) {
                printGameEndMessage();
            }
        }
    }
}


int Mtmchkin::getNumberOfRounds() const {
    return m_roundCount;
}

void Mtmchkin::printLeaderBoard() const {
    printLeaderBoardStartMessage();
    for (int i = 1; i <= m_winnersCount; i++) {
        for (Player* player : m_players) {
            if (player->getPlace() == i) {
                printPlayerLeaderBoard(player->getPlace(), *player);
            }
        }
    }

    int currentPlace = m_winnersCount + 1;
    for (Player* player : m_players) {
        if (player->getPlace() == notPlaced) {
            printPlayerLeaderBoard(currentPlace++, *player);
        }
    }

    for (; currentPlace <= m_numOfPlayers; currentPlace++) {
        for (Player* player : m_players) {
            if (player->getPlace() == currentPlace) {
                printPlayerLeaderBoard(currentPlace, *player);
            }
        }
    }
}



bool Mtmchkin::isGameOver() const{
    return (m_losersCount + m_winnersCount == m_numOfPlayers);
}
