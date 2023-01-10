#include <iostream>
#include "Card.h"
#include "Witch.h"
#include "Gremlin.h"
#include "Dragon.h"
#include "../Players/Player.h"
#include "../utilities.h"
#include <string>

Card::Card(const std::string& type) : m_type(type) {}


std::ostream& operator<<(std::ostream& os, const Card& card) {
    printCardDetails(os, card.m_type);
    if (card.m_type == "Witch") {
        printMonsterDetails(os, witchStrength, witchDamage, witchLoot);
    }
    if (card.m_type == "Gremlin") {
        printMonsterDetails(os, gremlinStrength, gremlinDamage, gremlinLoot);
    }
    if (card.m_type == "Dragon") {
        printMonsterDetails(os, dragonStrength, 0, dragonLoot, true);
    }
    printEndOfCardDetails(os);
    return os;
}


void Card::applyEncounter(Player& player) {};