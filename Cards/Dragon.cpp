#include "Dragon.h"

void Dragon::applyEncounter (Player& player) {
    if (player.getAttackStrength() >= m_strength) {
        player.levelUp();
        player.addCoins(m_loot);
        printWinBattle(player.getName(), "Dragon");
    }
    else {
        player.kill();
        printLossBattle(player.getName(), "Dragon");
    }
}