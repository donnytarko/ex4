#ifndef GREMLIN_H
#define GREMLIN_H

const int strength = 7;
const int loot = 3;
const int damage = 10;

class Gremlin : public Card {
    public:
    Gremlin () : Card() {

    }
    void applyEncounter (Player& player) const override {
        if (player.getAttackStrength() >= strength) {
            player.levelUp();
            player.addCoins(loot);
            printWinBattle(player.getName(), "Gremlin");
        }
        else {
            player.damage(damage);
            printLossBattle(player.getName(), "Gremlin");
        }
    }
};

#endif