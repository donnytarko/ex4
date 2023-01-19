#ifndef MONSTER_H
#define MONSTER_H
#include "Card.h"
#include <string>

class Monster : public Card {
    protected:
    int m_damage, m_strength, m_loot;
    public:
    explicit Monster(const std::string& type);
    virtual ~Monster() = default;
    Monster(const Monster&) = default;
    Monster& operator=(const Monster& other) = default;
};

#endif //Monster