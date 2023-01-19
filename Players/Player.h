#ifndef Player_H
#define Player_H
#include <string>

const int notPlaced = -1;

class Player {
    private:
    std::string m_name, m_class; 
    int m_place;

    protected:
    int m_coins, m_level, m_force, m_hp, m_maxHP;

    public:
    Player(std::string name, std::string playerClass);
    Player() = default;
    virtual ~Player() {};
    Player& operator=(const Player& other) = default;
    void levelUp();
    std::string getName() const;
    int getLevel() const;
    int getHealth() const;
    int getPlace() const;
    int getCoins() const;
    std::string getJob() const;
    int getForce() const;
    void buff(int forceIncrease);
    virtual void heal(int additionalHP);
    void damage(int damageTaken);
    bool isKnockedOut() const;
    virtual void addCoins(int additionalCoins);
    bool pay(int paymentAmount);
    virtual int getAttackStrength() const;
    void decreaseStrength();
    void kill();
    void place(int place);
};

std::ostream& operator<<(std::ostream& os, const Player& player);

#endif //EX2_Player_H