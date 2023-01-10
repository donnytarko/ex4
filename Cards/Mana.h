#ifndef MANA_H
#define MANA_H

class Mana : public Card {
    public:
    Mana() : Card("Mana") {}
    void applyEncounter (Player& player) override {
        if (player.getJob() == "Healer") {
            player.heal(20);
            printManaMessage(true);
        } else {
            player.heal(10);
            printManaMessage(false);
        }
    }
};

#endif