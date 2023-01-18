#include "Dragon.h"

void Dragon::applyEncounter (Player& player) {
    if (player.getAttackStrength() >= dragonStrength) {
        player.levelUp();
        player.addCoins(dragonLoot);
        printWinBattle(player.getName(), "Dragon");
    }
    else {
        player.kill();
        printLossBattle(player.getName(), "Dragon");
    }
}