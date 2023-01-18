#include "Well.h"

void Well::applyEncounter (Player& player) {
    if (player.getJob() != "Ninja") {
        player.damage(wellDamage);
        printWellMessage(false);
    } else {
        printWellMessage(true);
    }
}