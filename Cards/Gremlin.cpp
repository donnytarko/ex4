#include "Gremlin.h"

void Gremlin::applyEncounter (Player& player) {
    if (player.getAttackStrength() >= m_strength) {
        player.levelUp();
        player.addCoins(m_loot);
        printWinBattle(player.getName(), "Gremlin");
    }
    else {
        player.damage(m_damage);
        printLossBattle(player.getName(), "Gremlin");
    }
}