#ifndef BARFIGHT_H
#define BARFIGHT_H
#include "Card.h"

class Barfight : public Card {
    public:
    Barfight () : Card("Barfight") {}
    void applyEncounter (Player& player) override;
};

#endif