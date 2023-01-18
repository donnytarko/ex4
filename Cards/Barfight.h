#ifndef BARFIGHT_H
#define BARFIGHT_H
#include "Card.h"

const int barfightDamage = 10;

class Barfight : public Card {
    public:
    Barfight () : Card("Barfight") {}
    void applyEncounter (Player& player) override;
};

#endif