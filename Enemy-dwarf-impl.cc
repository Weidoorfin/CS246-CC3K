module dwarf;

import enemy;
import chamber;
import enums;

Dwarf::Dwarf(Player &player, Chamber &chamber)
    : Enemy{EnemyType::DWARF, player, chamber, 100, 20, 30} {}

Dwarf::~Dwarf() {}
