#ifndef Player_H
#define Player_H

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
    ~Player() = default;
    Player& operator=(const Player& other) = default;
    void printInfo() const;
    void levelUp();
    std::string getName() const;
    int getLevel() const;
    int getHealth() const;
    int getPlace() const;
    int getCoins() const;
    std::string getJob() const;
    int getForce() const;
    void buff(int forceIncrease);
    void heal(int additionalHP);
    void damage(int damageTaken);
    bool isKnockedOut() const;
    void addCoins(int additionalCoins);
    bool pay(int paymentAmount);
    int getAttackStrength() const;

};

#endif //EX2_Player_H