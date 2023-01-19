#ifndef WELL_H
#define WELL_H
#include "Card.h"


class Well : public Card {
    public:
    Well() : Card("Well") {}
    void applyEncounter (Player& player) override;
};

#endif