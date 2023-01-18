#ifndef MANA_H
#define MANA_H
#include "Card.h"

class Mana : public Card {
    public:
    Mana() : Card("Mana") {}
    void applyEncounter (Player& player) override;
};

#endif