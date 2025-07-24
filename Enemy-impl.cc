module enemy;

import <vector>;
import enums;
import character;
import entity;

bool Enemy::globalMoveDisabled = false;

Enemy::Enemy(Race race, int maxHP, int atk, int def, char symbol, int colour, Position pos)
    : Character{race, maxHP, atk, def, symbol, colour, pos} {
    entity = EntityType::ENEMY; // Set the entity type to ENEMY
}

void Enemy::toggleMove() {
    moveToggle = !moveToggle;
}

bool Enemy::getmoveToggle() const {
    return moveToggle;
}

void Enemy::resetMoveToggle() {
    moveToggle = false;
}

void Enemy::toggleGlobalMovement() {
    globalMoveDisabled = !globalMoveDisabled;
}

bool Enemy::isGlobalMovementDisabled() {
    return globalMoveDisabled;
}




