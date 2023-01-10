#ifndef WELL_H
#define WELL_H

const int damage = 10;

class Well : public Card {
    public:
    Well() : Card() {}
    void applyEncounter (Player& player) const override {
        if (player.getJob() != "Ninja") {
            player.damage(damage);
            printWellMessage(false);
        } else {
            printWellMessage(true);
        }
    }
};

#endif