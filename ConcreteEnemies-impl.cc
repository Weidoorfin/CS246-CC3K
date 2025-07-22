module concreteenemies;

import character;
import enemy;
import enums;

// Human implementation //////////////////////////////
Human::Human(Position pos)
    : Enemy{Race::HUMAN, 140, 20, 20, 'H', 0, pos} {}

Human::~Human() {}

// Dwarf implementation //////////////////////////////
Dwarf::Dwarf(Position pos)
    : Enemy{Race::DWARF, 100, 20, 30, 'W', 0, pos} {}

Dwarf::~Dwarf() {}

// Elf implementation //////////////////////////////
Elf::Elf(Position pos)
    : Enemy{Race::ELF, 140, 30, 10, 'E', 0, pos} {}

Elf::~Elf() {}

void Elf::attack(Character &target) {
    // Special attack logic for Elf
    Character::attack(target); // Call base class attack
    if (target.getRace() != Race::DROW) {
        // If the target is not a Drow, Elf deals additional damage
        Character::attack(target); 
    }
}

// Orc implementation //////////////////////////////
Orc::Orc(Position pos)
    : Enemy{Race::ORC, 180, 30, 25, 'O', 0, pos} {}

Orc::~Orc() {}

Orc::attack(Character &target) {
    // Special attack logic for Orc
    if (target.getRace() == Race::GOBLIN) {
        // If the target is a Goblin, Orc deals additional damage
        
    }
}
// Merchant implementation //////////////////////////////
Merchant::Merchant(Position pos)
    : Enemy{Race::MERCHANT, 30, 70, 5, 'M', 0, pos} {}

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
    : Enemy{Race::DRAGON, 150, 20, 20, 'D', 0, pos} {}

Dragon::~Dragon() {}

void Dragon::move(Direction dir) {
    // non-operational move for Dragon
}

// Halfling implementation //////////////////////////////
Halfling::Halfling(Position pos)
    : Enemy{Race::HALFLING, 100, 15, 20, 'L', 0, pos} {}

Halfling::~Halfling() {}
