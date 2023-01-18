#include "Barfight.h"

void Barfight::applyEncounter (Player& player) {
    if (player.getJob() != "Warrior") {
        player.damage(barfightDamage);
        printBarfightMessage(false);
    } else {
        printBarfightMessage(true);
    }
}