#ifndef Ninja_H
#define Ninja_H

class Ninja : public Player {
    public:
    Ninja(std::string name, std::string playerClass) : Player(name, playerClass) {}
    void addCoins(int additionalCoins) override { m_coins += 2 * additionalCoins; }
};

#endif