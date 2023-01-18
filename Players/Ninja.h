#ifndef Ninja_H
#define Ninja_H
#include "Player.h"

class Ninja : public Player {
    public:
    Ninja(std::string name) : Player(name, "Ninja") {}
    void addCoins(int additionalCoins) override { m_coins += 2 * additionalCoins; }
};

#endif