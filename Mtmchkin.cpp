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
#include <memory>

const int maxWordLength = 16;

Mtmchkin::Mtmchkin(const std::string &fileName) {
    printStartGameMessage();
    std::ifstream file(fileName);
    if (!file) {
		throw DeckFileNotFound();
    }
    int lineNumber = 0;
    std::string line;
    while (std::getline(file, line)) {
        lineNumber++;
        if (line.compare("Gremlin") == 0) {
            m_cards.push(std::unique_ptr<Card>(new Gremlin()));
        }
        else if (line.compare("Dragon") == 0) {
            m_cards.push(std::unique_ptr<Card>(new Dragon()));
        }
        else if (line.compare("Witch") == 0) {
            m_cards.push(std::unique_ptr<Card>(new Witch()));
        }
        else if (line.compare("Treasure") == 0) {
            m_cards.push(std::unique_ptr<Card>(new Treasure()));
        }
        else if (line.compare("Well") == 0) {
            m_cards.push(std::unique_ptr<Card>(new Well()));
        }
        else if (line.compare("Barfight") == 0) {
            m_cards.push(std::unique_ptr<Card>(new Barfight()));
        }
        else if (line.compare("Mana") == 0) {
            m_cards.push(std::unique_ptr<Card>(new Mana()));
        }
        else {
            throw DeckFileFormatError(lineNumber);
        }
    }
    if (lineNumber < 5) {
        throw DeckFileInvalidSize();
    }

    printEnterTeamSizeMessage();

    std::cin >> m_numOfPlayers;

    if (m_numOfPlayers > 6 || m_numOfPlayers < 2) {
        printInvalidTeamSize();
    }
    
    std::string name;
    std::string playerClass;
    bool invalidClass = false;
    bool invalidName = false;
    for (int i = 0; i < m_numOfPlayers; i++) {
        if (!invalidClass && !invalidName) {
            printInsertPlayerMessage();
        }
        if (invalidName) {
            printInvalidName();
            invalidName = false;
        } 
        if (invalidClass) {
            printInvalidClass();
            invalidClass = false;
        }

        std::cin >> name;

        if (name.length() > 15) {
            invalidName = true;
            i--;
            continue;
        }

        std::cin >> playerClass;

        if (playerClass == "Healer") {
            m_players.push_back(std::unique_ptr<Player>(new Healer(name)));
        } else if (playerClass == "Ninja") {
            m_players.push_back(std::unique_ptr<Player>(new Ninja(name)));
        } else if (playerClass == "Warrior") {
            m_players.push_back(std::unique_ptr<Player>(new Warrior(name)));
        } else {
            i--;
            invalidClass = true;
        }
    }

    m_roundCount = 0;
    m_winnersCount = 0;
    m_losersCount = 0;
}


void Mtmchkin::playRound() {
    m_roundCount ++;
    printRoundStartMessage(m_roundCount);
    for (int i = 0; i < (int)m_players.size(); i++) {
        if (m_players.at(i)->getPlace() == notPlaced) {
            printTurnStartMessage(m_players.at(i)->getName());
            m_cards.front()->applyEncounter(*m_players.at(i));
            m_cards.push(std::move(m_cards.front()));
            m_cards.pop();
            if (m_players.at(i)->getLevel() >= 10) {
                m_players.at(i)->place(++m_winnersCount);
            }
            if (m_players.at(i)->isKnockedOut()) {
                m_players.at(i)->place(m_numOfPlayers - m_losersCount);
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
        for (int j = 0; j < (int)m_players.size(); j++) {
            if (m_players.at(j)->getPlace() == i) {
                printPlayerLeaderBoard(m_players.at(j)->getPlace(), *m_players.at(j));
            }
        }
    }

    int currentPlace = m_winnersCount + 1;
    for (int i = 0; i < (int)m_players.size(); i++) {
        if (m_players.at(i)->getPlace() == notPlaced) {
            printPlayerLeaderBoard(currentPlace++, *m_players.at(i));
        }
    }
    for (; currentPlace <= m_numOfPlayers; currentPlace++) {
        for (int i = 0; i < (int)m_players.size(); i++) {
            if (m_players.at(i)->getPlace() == currentPlace) {
                printPlayerLeaderBoard(currentPlace, *m_players.at(i));
            }
        }
    }
}



bool Mtmchkin::isGameOver() const{
    return (m_losersCount + m_winnersCount == m_numOfPlayers);
}
