#include <iostream>
#include "Player.h"
#include "utilities.h"

Player::Player(std::string name, PlayerClass playerClass) {
    m_name = name;
    m_level = 1;
    m_coins = 0;
}

void Player::printInfo() const {
}

std::string Player::getName() const {
    return m_name;
}


void Player::levelUp() {
    if (m_level < 10) {
        m_level++;
    }
}

int Player::getLevel() const {
    return m_level;
}

int Player::getHealth() const {
    return m_hp;
}

void Player::buff(int forceIncrease) {
    m_force += forceIncrease;
}

void Player::heal(int additionalHP) {
    if (m_hp + additionalHP > m_maxHP) {
        m_hp = m_maxHP;
    } 
    else if (m_hp > 0) {
        m_hp += additionalHP;
    }

}

void Player::damage(int damageTaken) {
    if (m_hp - damageTaken < 0) {
        m_hp = 0;
    }
    else if (damageTaken >= 0) {
        m_hp -= damageTaken;
    }
}

bool Player::isKnockedOut() const {
    return m_hp == 0;
}

void Player::addCoins(int additionalCoins) {
    m_coins += additionalCoins;
}

bool Player::pay(int paymentAmount) {
    if (m_coins - paymentAmount >= 0) {
        m_coins -= paymentAmount;
        return true;
    }
    return false;
}

int Player::getAttackStrength() const {
    return m_level + m_force;
}
