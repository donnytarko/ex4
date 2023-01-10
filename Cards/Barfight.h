#ifndef BARFIGHT_H
#define BARFIGHT_H

const int barfightDamage = 10;

class Barfight : public Card {
    public:
    Barfight () : Card("Barfight") {}
    void applyEncounter (Player& player) const override {
        if (player.getJob() != "Warrior") {
            player.damage(barfightDamage);
            printBarfightMessage(false);
        } else {
            printBarfightMessage(true);
        }
    }
};

#endif