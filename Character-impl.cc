module character;

import position;

int Character::getAtk() const { return atk; }
int Character::getDef() const { return def; }
int Character::getMaxHP() const { return maxHP; }
bool Character::isAlive() const { return currentHP >= 0; }
void Character::move(Direction dir) {
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
