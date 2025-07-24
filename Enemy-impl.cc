module enemy;

import <vector>;
import enums;
import character;
import entity;

Enemy::Enemy(Race race, int maxHP, int atk, int def, char symbol, int colour, Position pos)
    : Character{race, maxHP, atk, def, symbol, colour, pos} {
    entity = EntityType::ENEMY; // Set the entity type to ENEMY
}

void Enemy::toggleMove() {
    moveToggle = true;
}

bool Enemy::getmoveToggle() const {
    return moveToggle;
}




