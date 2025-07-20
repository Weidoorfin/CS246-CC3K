module elf;

import enemy;
import chamber;
import enums;

Elf::Elf(Chamber &chamber)
    : Enemy{EnemyType::ELF, player, chamber, 140, 30, 10} {}

Elf::~Elf() {}
