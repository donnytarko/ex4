//
// Created by Daniel_Meents on 07/04/2022.
//
#ifndef EX2_Card_H
#define EX2_Card_H

#include <string>
#include "../Players/Player.h"
#include "../utilities.h"
#include <iostream>
#include <string>

class Card {

private:
std::string m_type;

public:
    /*
     * C'tor of Card class
     *
     * @param type - The type of the card.
     * @return
     *      A new instance of Card.
    */
    Card(const std::string& type);


    /*
     * Handling the player's applyEncounter with the card:
     *
     * @param player - The player.
     * @return
     *      void
    */
    virtual void applyEncounter(Player& player) const;

    Card(const Card&) = default;
    ~Card() = default;
    Card& operator=(const Card& other) = default;
    friend std::ostream& operator<<(std::ostream& os, const Card& card);
};


#endif //EX2_Card_H
