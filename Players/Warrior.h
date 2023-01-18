#ifndef Warrior_H
#define Warrior_H
#include "Player.h"

class Warrior : public Player {
    public:
    Warrior(std::string name) : Player(name, "Warrior") {}
    int getAttackStrength() const override;
};

#endif