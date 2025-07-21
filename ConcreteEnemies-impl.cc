module concreteenemies;

import enemy;
import enums;

// Human implementation //////////////////////////////
Human::Human()
    : Enemy{EnemyType::HUMAN, 140, 20, 20} {}

Human::~Human() {}

// Dwarf implementation //////////////////////////////
Dwarf::Dwarf()
    : Enemy{EnemyType::DWARF, 100, 20, 30} {}

Dwarf::~Dwarf() {}

// Elf implementation //////////////////////////////
Elf::Elf()
    : Enemy{EnemyType::ELF, 140, 30, 10} {}

Elf::~Elf() {}

// Orc implementation //////////////////////////////
Orc::Orc()
    : Enemy{EnemyType::ORC, 180, 30, 25} {}

Orc::~Orc() {}

// Merchant implementation //////////////////////////////
Merchant::Merchant()
    : Enemy{EnemyType::MERCHANT, 30, 70, 5} {}

Merchant::~Merchant() {}

void Merchant::onHit(Character &whoFrom) {
    // Implement the logic for handling a hit from another character
    int damage = ceil((100 / (100 + getDef())) * whoFrom.getAtk());
    if (damage < currentHP) {
        currentHP -= damage;
    } else {
        currentHP = 0; // Character dies
    }
    hostile = true; // Merchant becomes hostile after being hit
    notifyObservers();
}

// Dragon implementation //////////////////////////////
Dragon::Dragon()
    : Enemy{EnemyType::DRAGON, 150, 20, 20} {}

Dragon::~Dragon() {}

// Halfling implementation //////////////////////////////
Halfling::Halfling()
    : Enemy{EnemyType::HALFLING, 100, 15, 20} {}

Halfling::~Halfling() {}
