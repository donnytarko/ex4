#ifndef DRAGON_H
#define DRAGON_H
#include "Card.h"
const int dragonStrength = 25;
const int dragonLoot = 1000;

class Dragon : public Card {
    public:
    Dragon () : Card("Dragon") {}
    void applyEncounter (Player& player) override;
};

#endif