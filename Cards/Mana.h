#ifndef MANA_H
#define MANA_H

class Mana : public Card {
    public:
    Mana() : Card("Mana") {}
    void applyEncounter (Player& player) override {
        if (player.getJob() == "Healer") {
            player.heal(10);
            printManaMessage(true);
        } else {
            printManaMessage(false);
        }
    }
};

#endif