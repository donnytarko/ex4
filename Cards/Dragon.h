#ifndef DRAGON_H
#define DRAGON_H
#include "Monster.h"

class Dragon : public Monster {
    public:
    Dragon () : Monster("Dragon") {}
    void applyEncounter (Player& player) override;
};

#endif