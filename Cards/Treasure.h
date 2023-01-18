#ifndef TREASURE_H
#define TREASURE_H
#include "Card.h"

const int coinsAmount = 10;

class Treasure : public Card {
    public:
    Treasure() : Card("Treasure") {}
    void applyEncounter (Player& player) override;
};

#endif