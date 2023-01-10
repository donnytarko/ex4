#ifndef WELL_H
#define WELL_H

const int wellDamage = 10;

class Well : public Card {
    public:
    Well() : Card() {}
    void applyEncounter (Player& player) const override {
        if (player.getJob() != "Ninja") {
            player.damage(wellDamage);
            printWellMessage(false);
        } else {
            printWellMessage(true);
        }
    }
};

#endif