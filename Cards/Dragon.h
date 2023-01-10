#ifndef DRAGON_H
#define DRAGON_H

const int dragonStrength = 25;
const int dragonLoot = 1000;

class Dragon : public Card {
    public:
    Dragon () : Card() {}
    void applyEncounter (Player& player) const override {
        if (player.getAttackStrength() >= dragonStrength) {
            player.levelUp();
            player.addCoins(dragonLoot);
            printWinBattle(player.getName(), "Dragon");
        }
        else {
            player.kill();
            printLossBattle(player.getName(), "Dragon");
        }
    }
};

#endif