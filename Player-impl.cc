module player;

Player::Player(PlayerRace race) : Race{race}, Gold{0} {}

PlayerRace Player::getRace() const {
    return Race;
}

int Player::getGold() const {
    return Gold;
}

void Player::gainGold(int amount) {
    Gold += amount;
}

// Default onKill does nothing, subclasses override if needed
void Player::onKill(Character &enemy) {}

void Player::onTurn() {}

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


