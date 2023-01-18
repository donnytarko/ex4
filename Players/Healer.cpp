#include "Healer.h"

void Healer::heal(int additionalHP) {
    if ((m_hp + (2 * additionalHP)) > m_maxHP) {
    m_hp = m_maxHP;
    } 
    else if (m_hp > 0) {
        m_hp += 2 * additionalHP;
    }
}