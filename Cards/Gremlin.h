#ifndef GREMLIN_H
#define GREMLIN_H

const int gremlinStrength = 7;
const int gremlinLoot = 3;
const int gremlinDamage = 10;

class Gremlin : public Card {
    public:
    Gremlin () : Card("Gremlin") {

    }
    void applyEncounter (Player& player) override {
        if (player.getAttackStrength() >= gremlinStrength) {
            player.levelUp();
            player.addCoins(gremlinLoot);
            printWinBattle(player.getName(), "Gremlin");
        }
        else {
            player.damage(gremlinDamage);
            printLossBattle(player.getName(), "Gremlin");
        }
    }
};

#endif