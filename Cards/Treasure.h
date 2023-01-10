#ifndef TREASURE_H
#define TREASURE_H

const int coinsAmount = 10;

class Treasure : public Card {
    public:
    Treasure() : Card("Treasure") {}
    void applyEncounter (Player& player) override {
        player.addCoins(coinsAmount);
    }
};

#endif