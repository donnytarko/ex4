#ifndef TREASURE_H
#define TREASURE_H
#include "Card.h"

class Treasure : public Card {
    public:
    Treasure() : Card("Treasure") {}
    void applyEncounter (Player& player) override;
};

#endif