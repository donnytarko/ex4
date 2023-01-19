#include "Barfight.h"

void Barfight::applyEncounter (Player& player) {
    const int barfightDamage = 10;

    if (player.getJob() != "Warrior") {
        player.damage(barfightDamage);
        printBarfightMessage(false);
    } else {
        printBarfightMessage(true);
    }
}