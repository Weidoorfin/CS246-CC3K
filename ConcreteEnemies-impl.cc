module concreteenemies;

import character;
import enemy;
import enums;

// Human implementation //////////////////////////////
Human::Human(Position pos)
    : Enemy{EnemyType::HUMAN, 140, 20, 20, 'H', 0, pos} {}

Human::~Human() {}

// Dwarf implementation //////////////////////////////
Dwarf::Dwarf(Position pos)
    : Enemy{EnemyType::DWARF, 100, 20, 30, 'W', 0, pos} {}

Dwarf::~Dwarf() {}

// Elf implementation //////////////////////////////
Elf::Elf(Position pos)
    : Enemy{EnemyType::ELF, 140, 30, 10, 'E', 0, pos} {}

Elf::~Elf() {}

void Elf::attack(Character &target) {
    // Special attack logic for Elf
    Character::attack(target); // Call base class attack
    if (target.getR)
}

// Orc implementation //////////////////////////////
Orc::Orc(Position pos)
    : Enemy{EnemyType::ORC, 180, 30, 25, 'O', 0, pos} {}

Orc::~Orc() {}

// Merchant implementation //////////////////////////////
Merchant::Merchant(Position pos)
    : Enemy{EnemyType::MERCHANT, 30, 70, 5, 'M', 0, pos} {}

Merchant::~Merchant() {}

void Merchant::onHit(Character &whoFrom) {
    Character::onHit(whoFrom); // Call base class onHit to handle damage
    hostile = true; // Merchant becomes hostile after being hit
}

void Merchant::attack(Character &target) {
    if (hostile) {
        Character::attack(target); // Only attack if hostile
    }
}

// Dragon implementation //////////////////////////////
Dragon::Dragon(Position pos)
    : Enemy{EnemyType::DRAGON, 150, 20, 20, 'D', 0, pos} {}

Dragon::~Dragon() {}

void Dragon::move(Direction dir) {
    // non-operational move for Dragon
}

// Halfling implementation //////////////////////////////
Halfling::Halfling(Position pos)
    : Enemy{EnemyType::HALFLING, 100, 15, 20, 'L', 0, pos} {}

Halfling::~Halfling() {}
