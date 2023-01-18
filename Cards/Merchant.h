#ifndef MERCHANT_H
#define MERCHANT_H
#include "Card.h"

class Merchant : public Card {
    public:
    Merchant() : Card("Merchant") {}
    void applyEncounter (Player& player) override;
};

#endif