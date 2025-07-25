module player;

import <iostream>; // delete
import <memory>;
import <cmath>;
import enums;
import character;
import PRNG;
import position;

Player::Player(Race race, int maxHP, int atk, int def, Position pos)
    : Character{race, maxHP, atk, def, '@', 40, pos}, Gold{0}, totGold{0} {
    entity = EntityType::PLAYER;
}

Player::~Player() {} 

int Player::getGold() const {
    return Gold;
}

void Player::gainGold(int amount) {
    Gold += amount;
    totGold += amount;
}

double Player::getScore() const {
    return totGold;
}


void Player::onTurn() {}


void Player::loseHP(int dec) {
    if (currentHP - dec >= 0) {
        currentHP -= dec;
    } else {
        currentHP = 0;
    }
}

void Player::gainHP(int inc) {
    if (currentHP + inc <= getMaxHP()) {
        currentHP += inc;
    } else {
        currentHP = getMaxHP();
    }
}

void Player::attack(Character &target) {
    if (target.getRace() == Race::HALFLING) {
        PRNG rng;
        int result = rng(1);
        if (result == 0) {
            return;
        }
    }
    target.onHit(*this);
}

void Player::onHit(Character &whoFrom) {
    int damage = std::ceil((100.f / (100.f + getDef())) * whoFrom.getAtk());
    loseHP(damage);
}


double Player::getPotionMultiplier() const {
    return 1.0;
}

int Player::getCurrentHP() const {
    return currentHP;
}

std::unique_ptr<Player> Player::applyEffect(std::unique_ptr<Player> player) {
    return player;
}
