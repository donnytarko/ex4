#ifndef WITCH_H
#define WITCH_H
#include "Card.h"

const int witchStrength = 11;
const int witchLoot = 2;
const int witchDamage = 10;
class Witch : public Card {
    public:
    Witch() : Card("Witch") {}
    void applyEncounter (Player& player) override {
        if (player.getAttackStrength() >= witchStrength) {
            player.levelUp();
            player.addCoins(witchLoot);
            printWinBattle(player.getName(), "Witch");
        }
        else {
            player.damage(witchDamage);
            player.decreaseStrength();
            printLossBattle(player.getName(), "Witch");
        }
    }
};

#endif