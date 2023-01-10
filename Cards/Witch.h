#ifndef WITCH_H
#define WITCH_H

const int witchStrength = 12;
const int witchLoot = 3;
const int witchDamage = 10;
std::string witchName = "Witch";
class Witch : public Card {
    public:
    Witch() : Card(witchName) {}
    void applyEncounter (Player& player) override {
        if (player.getAttackStrength() >= witchStrength) {
            player.levelUp();
            player.addCoins(witchLoot);
            printWinBattle(player.getName(), "Witch");
        }
        else {
            player.damage(witchDamage);
            player.decreaseStrength();
            printLossBattle(player.getName(), "Witch");
        }
    }
};

#endif