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