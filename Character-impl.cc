module character;

import <cmath>;
import position;
import enums;

Character::Character(Chamber &chamber, int maxHP, int atk, int def)
    : chamber{chamber}, maxHP{maxHP}, atk{atk}, def{def} {}
int Character::getAtk() const { return atk; }
int Character::getDef() const { return def; }
int Character::getMaxHP() const { return maxHP; }
bool Character::isAlive() const { return currentHP >= 0; }
Chamber &getChamber() const { return chamber; }

void Character::move(Direction dir) {
    Position npos = pos;
    switch(dir) {
        case Direction::N:
            npos.y += 1;
            break;
        case Direction::NE:
            npos.x += 1; npos.y += 1;
        case Direction::E:
            npos.x += 1;
            break;
        case Direction::SE:
            npos.x += 1; npos.y -= 1;
            break;
        case Direction::S:
            npos.y -= 1;
            break;
        case Direction::SW:
            npos.x -= 1; npos.y -= 1;
            break;
        case Direction::W:
            npos.x -= 1;
            break;
        case Direction::NW:
            npos.x -= 1; npos.y += 1;
            break;
    }
    // check if the new position is valid
    if (chamber.tilevalid(npos)) {
        pos = npos; // update position
        notifyObservers(); // notify observers of the move
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
