#include "Gremlin.h"

void Gremlin::applyEncounter (Player& player) {
    if (player.getAttackStrength() >= gremlinStrength) {
        player.levelUp();
        player.addCoins(gremlinLoot);
        printWinBattle(player.getName(), "Gremlin");
    }
    else {
        player.damage(gremlinDamage);
        printLossBattle(player.getName(), "Gremlin");
    }
}