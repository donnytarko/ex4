#ifndef BARFIGHT_H
#define BARFIGHT_H

const int damage = 10;

class Barfight : public Card {
    public:
    Barfight () : Card() {}
    void applyEncounter (Player& player) const override {
        if (player.getJob() != "Warrior") {
            player.damage(damage);
            printBarfightMessage(false);
        } else {
            printBarfightMessage(true);
        }
    }
};

#endif