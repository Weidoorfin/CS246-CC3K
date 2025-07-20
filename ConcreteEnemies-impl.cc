module concreteenemies;

import enemy;
import chamber;
import enums;

// Human implementation //////////////////////////////
Human::Human(Player &player, Chamber &chamber)
    : Enemy{EnemyType::HUMAN, player, chamber, 140, 20, 20} {}

Human::~Human() {}

// Dwarf implementation //////////////////////////////
Dwarf::Dwarf(Player &player, Chamber &chamber)
    : Enemy{EnemyType::DWARF, player, chamber, 100, 20, 30} {}

Dwarf::~Dwarf() {}

// Elf implementation //////////////////////////////
Elf::Elf(Chamber &chamber)
    : Enemy{EnemyType::ELF, player, chamber, 140, 30, 10} {}

Elf::~Elf() {}

// Orc implementation //////////////////////////////
Orc::Orc(Player &player, Chamber &chamber)
    : Enemy{EnemyType::ORC, player, chamber, 180, 30, 25} {}

Orc::~Orc() {}

// Merchant implementation //////////////////////////////
Merchant::Merchant(Player &player, Chamber &chamber)
    : Enemy{EnemyType::MERCHANT, player, chamber, 30, 70, 5} {}

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
Dragon::Dragon(Player &player, Chamber &chamber)
    : Enemy{EnemyType::DRAGON, player, chamber, 150, 20, 20} {}

Dragon::~Dragon() {}

// Halfling implementation //////////////////////////////
Halfling::Halfling(Player &player, Chamber &chamber)
    : Enemy{EnemyType::HALFLING, player, chamber, 100, 15, 20} {}

Halfling::~Halfling() {}
