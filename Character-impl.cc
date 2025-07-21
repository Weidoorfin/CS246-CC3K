module character;

import <cmath>;
import position;
import enums;

Character::Character(int maxHP, int atk, int def)
    : maxHP{maxHP}, atk{atk}, def{def} {}
int Character::getAtk() const { return atk; }
int Character::getDef() const { return def; }
int Character::getMaxHP() const { return maxHP; }
bool Character::isAlive() const { return currentHP >= 0; }

void Character::move(Direction dir) {
    // assumes the new direction is valid
    switch(dir) {
        case Direction::N:
            pos.y += 1;
            break;
        case Direction::NE:
            pos.x += 1; pos.y += 1;
        case Direction::E:
            pos.x += 1;
            break;
        case Direction::SE:
            pos.x += 1; pos.y -= 1;
            break;
        case Direction::S:
            pos.y -= 1;
            break;
        case Direction::SW:
            pos.x -= 1; pos.y -= 1;
            break;
        case Direction::W:
            pos.x -= 1;
            break;
        case Direction::NW:
            pos.x -= 1; pos.y += 1;
            break;
    }
}

void Character::onHit(Character &whoFrom) {
    // Implement the logic for handling a hit from another character
    int damage = ceil((100 / (100 + getDef())) * whoFrom.getAtk());
    if (damage < currentHP) {
        currentHP -= damage;
    } else {
        currentHP = 0; // Character dies
    }
    notifyObservers();
}
