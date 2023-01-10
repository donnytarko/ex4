#ifndef Warrior_H
#define Warrior_H

class Warrior : public Player {
    public:
    Warrior(std::string name, std::string playerClass) : Player(name, playerClass) {}
    int getAttackStrength() const override { return (m_level + (2 * m_force)); }
};

#endif