#ifndef WELL_H
#define WELL_H
#include "Card.h"

const int wellDamage = 10;

class Well : public Card {
    public:
    Well() : Card("Well") {}
    void applyEncounter (Player& player) override {
        if (player.getJob() != "Ninja") {
            player.damage(wellDamage);
            printWellMessage(false);
        } else {
            printWellMessage(true);
        }
    }
};

#endif