#include "Well.h"

void Well::applyEncounter (Player& player) {
    const int wellDamage = 10;
    if (player.getJob() != "Ninja") {
        player.damage(wellDamage);
        printWellMessage(false);
    } else {
        printWellMessage(true);
    }
}