module halfling;

import enemy;
import chamber;
import enums;

Halfling::Halfling(Player &player, Chamber &chamber)
    : Enemy{EnemyType::HALFLING, player, chamber, 100, 15, 20} {}

Halfling::~Halfling() {}
