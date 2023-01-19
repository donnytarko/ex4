#include <iostream>
#include "Monster.h"
#include "../Players/Player.h"
#include "../utilities.h"
#include <string>

Card::Card(const std::string& type) : m_type(type) {}


std::ostream& operator<<(std::ostream& os, const Card& card) {
    const int witchStrength = 11;
    const int witchDamage = 10;
    const int witchLoot = 2;
    const int gremlinStrength = 5;
    const int gremlinDamage = 10;
    const int gremlinLoot = 2;
    const int dragonStrength = 25;
    const int dragonDamage = 0;
    const int dragonLoot = 1000;

    printCardDetails(os, card.m_type);
    if (card.m_type == "Witch") {
        printMonsterDetails(os, witchStrength, witchDamage, witchLoot);
    }
    if (card.m_type == "Gremlin") {
        printMonsterDetails(os, gremlinStrength, gremlinDamage, gremlinLoot);
    }
    if (card.m_type == "Dragon") {
        printMonsterDetails(os, dragonStrength, dragonDamage, dragonLoot, true);
    }
    printEndOfCardDetails(os);
    return os;
}
