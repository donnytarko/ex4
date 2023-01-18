#include "Mana.h"

void Mana::applyEncounter (Player& player) {
    if (player.getJob() == "Healer") {
        player.heal(10);
        printManaMessage(true);
    } else {
        printManaMessage(false);
    }
}