#ifndef DRAGON_H
#define DRAGON_H

const int dragonStrength = 25;
const int dragonLoot = 1000;

class Dragon : public Card {
    public:
    Dragon () : Card("Dragon") {}
    void applyEncounter (Player& player) override {
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