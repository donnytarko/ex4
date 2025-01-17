#ifndef MTMCHKIN_H_
#define MTMCHKIN_H_
#include "Players/Player.h"
#include "Cards/Card.h"
#include <queue>
#include <vector>
#include <string>
#include <iostream>
#include <memory>

class Mtmchkin{
private:
    int m_numOfPlayers, m_roundCount, m_winnersCount, m_losersCount;
    std::queue<std::unique_ptr<Card>> m_cards;
    std::vector<std::unique_ptr<Player>> m_players;
public:
    
    /*
    * C'tor of Mtmchkin class
    *
    * @param filename - a file which contains the cards of the deck.
    * @return
    *      A new instance of Mtmchkin.
    */
    explicit Mtmchkin(const std::string &fileName);

    Mtmchkin& operator=(const Mtmchkin& other) = delete;
    Mtmchkin(const Mtmchkin& other) = delete;
    /*
    * Play the next Round of the game - according to the instruction in the exercise document.
    *
    * @return
    *      void
    */
    void playRound();
    
    /*
    * Prints the leaderBoard of the game at a given stage of the game - according to the instruction in the exercise document.
    *
    * @return
    *      void
    */
    void printLeaderBoard() const;
    
    /*
    *  Checks if the game ended:
    *
    *  @return
    *          True if the game ended
    *          False otherwise
    */
    bool isGameOver() const;
    
	/*
    *  Returns the number of rounds played.
    *
    *  @return
    *          int - number of rounds played
    */
    int getNumberOfRounds() const;
};



#endif /* MTMCHKIN_H_ */
