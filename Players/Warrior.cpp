#include "Warrior.h"

int Warrior::getAttackStrength() const { 
    return (m_level + (2 * m_force));
}