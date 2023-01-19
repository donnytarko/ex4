#include "Monster.h"

 Monster::Monster(const std::string& type) : Card(type) {
    if (type == "Dragon") {
        m_strength = 25;
        m_loot = 1000;
    }
    if (type == "Gremlin") {
        m_strength = 5;
        m_damage = 10;
        m_loot = 2;  
    }
    if (type == "Witch") {
        m_strength = 11;
        m_damage = 10;
        m_loot = 2;
    }
 }
