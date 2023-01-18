#ifndef Healer_H
#define Healer_H
#include "Player.h"

class Healer : public Player {
    public:
    Healer(std::string name) : Player(name, "Healer") {}
    void heal(int additionalHP) override;
};

#endif