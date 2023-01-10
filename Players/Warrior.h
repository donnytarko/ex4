#ifndef Warrior_H
#define Warrior_H

class Warrior : public Player {
    public:
    Warrior(std::string name) : Player(name, "Warrior") {}
    int getAttackStrength() const override { return (m_level + (2 * m_force)); }
};

#endif