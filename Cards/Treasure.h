#ifndef TREASURE_H
#define TREASURE_H

const int coinsAmount = 10;

class Treasure : public Card {
    public:
    Treasure() : Card() {}
    void applyEncounter (Player& player) const override {
        player.addCoins(coinsAmount);
    }
};

#endif