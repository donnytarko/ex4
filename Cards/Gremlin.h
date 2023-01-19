#ifndef GREMLIN_H
#define GREMLIN_H
#include "Monster.h"

class Gremlin : public Monster {
    public:
    Gremlin () : Monster("Gremlin") {

    }
    void applyEncounter (Player& player) override;
};

#endif