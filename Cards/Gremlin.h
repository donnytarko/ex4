#ifndef GREMLIN_H
#define GREMLIN_H
#include "Card.h"

const int gremlinStrength = 5;
const int gremlinLoot = 2;
const int gremlinDamage = 10;

class Gremlin : public Card {
    public:
    Gremlin () : Card("Gremlin") {

    }
    void applyEncounter (Player& player) override;
};

#endif