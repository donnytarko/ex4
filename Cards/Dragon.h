#ifndef DRAGON_H
#define DRAGON_H

const int strength = 25;
const int loot = 1000;

class Dragon : public Card {
    public:
    Dragon () : Card() {}
    void applyEncounter (Player& player) const override {
        if (player.getAttackStrength() >= strength) {
            player.levelUp();
            player.addCoins(loot);
            printWinBattle(player.getName(), "Dragon");
        }
        else {
            player.kill();
            printLossBattle(player.getName(), "Dragon");
        }
    }
};

#endif