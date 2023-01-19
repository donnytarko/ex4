#include "Treasure.h"

void Treasure::applyEncounter (Player& player) {
    const int coinsAmount = 10;
    printTreasureMessage();
    player.addCoins(coinsAmount);
}