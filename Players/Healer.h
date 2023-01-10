#ifndef Healer_H
#define Healer_H

class Healer : public Player {
    public:
    Healer(std::string name) : Player(name, "Healer") {}
    void heal(int additionalHP) override {
        if ((m_hp + (2 * additionalHP)) > m_maxHP) {
        m_hp = m_maxHP;
        } 
        else if (m_hp > 0) {
            m_hp += 2 * additionalHP;
        }
    }
};

#endif