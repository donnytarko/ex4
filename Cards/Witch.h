#ifndef WITCH_H
#define WITCH_H
#include "Monster.h"

class Witch : public Monster {
    public:
    Witch() : Monster("Witch") {}
    void applyEncounter (Player& player) override;
};

#endif