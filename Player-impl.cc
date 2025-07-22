module player;

import <memory>;
import <cmath>;
import enums;
import character;
import PRNG;
import randomengine;

Player::Player(Race race, int maxHP, int atk, int def, Position pos)
    : Character(maxHP, atk, def, '@', 0, pos), Race{race}, Gold{0}, totGold{0} {
    entity = EntityType::PLAYER;
}

PlayerRace Player::getRace() const {
    return Race;
}

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

// Default onKill does nothing, subclasses override if needed
void Player::onKill(Character &enemy) {}

void Player::onTurn() {}

void Player::onKill() {}

void Player::loseHP(int dec) {
    if (currentHP - dec >= 0) {
        currentHP -= dec;
    } else {
        currentHP = 0;
    }
}

void Player::gainHP(int inc) {
    if (currentHP + inc <= maxHP) {
        currentHP += inc;
    } else {
        currentHP = maxHP;
    }
}

void Player::attack(Character &target) {
    if (target.getRace() == Race::HALFLING) {
        RandomEngine rng;
        if (rng.chance(50)) {
            return;
        }
    }
    target.onHit(*this);
    if( !target.isAlive()) {
        onKill();
    }
}

void Player::onHit(Character &whoFrom) {
    int damage = std::ceil((100 / (100 + whoFrom.getDef())) * whoFrom.getAtk());
    loseHP(damage);
}

void Player::useItem(Item &item) {
    auto newPlayer = item.applyEffect(std::make_unique<Player>(*this));
    if (newPlayer) {
        *this = *newPlayer;
    }
}

double Player::getPotionMultiplier() const {
    return 1.0;
}
