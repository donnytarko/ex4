#ifndef WITCH_H
#define WITCH_H

const int strength = 12;
const int loot = 3;
const int damage = 10;

class Witch : public Card {
    public:
    Witch() : Card() {}
    void applyEncounter (Player& player) const override {
        if (player.getAttackStrength() >= strength) {
            player.levelUp();
            player.addCoins(loot);
            printWinBattle(player.getName(), "Witch");
        }
        else {
            player.damage(damage);
            player.decreaseStrength();
            printLossBattle(player.getName(), "Witch");
        }
    }
};

#endif