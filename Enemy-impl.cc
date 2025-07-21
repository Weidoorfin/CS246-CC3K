module enemy;

import <vector>;
import enums;
import entity;

Enemy::Enemy(EnemyType type, int maxHP, int atk, int def, char symbol, int colour, Position pos)
    : Character{maxHP, atk, def, symbol, colour, pos}, type{type} {
    entity = EntityType::ENEMY; // Set the entity type to ENEMY
}



