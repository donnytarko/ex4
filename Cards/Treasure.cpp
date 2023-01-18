#include "Treasure.h"

void Treasure::applyEncounter (Player& player) {
    printTreasureMessage();
    player.addCoins(coinsAmount);
}