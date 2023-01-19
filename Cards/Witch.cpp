#include "Witch.h"

void Witch::applyEncounter (Player& player) {
    if (player.getAttackStrength() >= m_strength) {
        player.levelUp();
        player.addCoins(m_loot);
        printWinBattle(player.getName(), "Witch");
    }
    else {
        player.damage(m_damage);
        player.decreaseStrength();
        printLossBattle(player.getName(), "Witch");
    }
}