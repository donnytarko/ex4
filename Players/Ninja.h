#ifndef Ninja_H
#define Ninja_H
#include "Player.h"

class Ninja : public Player {
    public:
    Ninja(std::string name) : Player(name, "Ninja") {}
    void addCoins(int additionalCoins) override;
};

#endif