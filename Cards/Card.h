//
// Created by Daniel_Meents on 07/04/2022.
//
#ifndef EX2_Card_H
#define EX2_Card_H

#include <string>
#include "Player.h"
#include "utilities.h"

/*
 *  CardType:
 *  Each card has an type:
 *  BATTLE - Battle against a monster.
 *  BUFF - Increase your player's force by 'm_force' points of CardStats.
 *  HEAL - Increase your player's HP by 'm_heal' points  of CardStats (no more than maxHP points).
 *  TREASURE - Get 'm_profit' coins of CardStats.
*/
enum class CardType {Gremlin, Battle, Buff, Heal, Treasure}; // The type of the Card

class Card {
private:
CardType m_effect;

public:
    /*
     * C'tor of Card class
     *
     * @param type - The type of the card.
     * @return
     *      A new instance of Card.
    */
    Card(CardType type);


    /*
     * Handling the player's applyEncounter with the card:
     *
     * @param player - The player.
     * @return
     *      void
    */
    void applyEncounter(Player& player) const;


    /*
     * Prints the card info:
     *
     * @return
     *      void
    */
    void printInfo() const;


    /*
     * C'tor to the "default card" - Treasure card that gives 0 coins
    */
    Card(): m_effect(CardType::Treasure) {}


    /*
     * Here we are explicitly telling the compiler to use the default methods
    */
    Card(const Card&) = default;
    ~Card() = default;
    Card& operator=(const Card& other) = default;
};


#endif //EX2_Card_H
