#include "Witch.h"

void Witch::applyEncounter (Player& player) {
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