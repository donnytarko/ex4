#include <iostream>
#include "Player.h"
#include "../utilities.h"
#include <string>

Player::Player(std::string name, std::string playerClass) {
    m_name = name;
    m_class = playerClass;
    m_level = 1;
    m_coins = 10;
    m_force = 5;
    m_maxHP = 100;
    m_hp = 100;
    m_place = notPlaced;
}

std::ostream& operator<<(std::ostream& os, const Player& player) {
    printPlayerDetails(os, player.getName(), player.getJob(), player.getLevel(), 
                        player.getForce(), player.getHealth(), player.getCoins());
    return os;
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

int Player::getForce() const {
    return m_force;
}

std::string Player::getJob() const {
    return m_class;
}

int Player::getCoins() const {
    return m_coins;
}

int Player::getPlace() const {
    return m_place;
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

void Player::decreaseStrength() {
    if (m_force > 0) {
        m_force--;
    }
}

void Player::kill() {
    m_hp = 0;
}

void Player::place(int place) {
    m_place = place;
}