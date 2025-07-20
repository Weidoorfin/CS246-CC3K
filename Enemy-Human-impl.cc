module human;

import enemy;
import chamber;
import enums;

Human::Human(Player &player, Chamber &chamber)
    : Enemy{EnemyType::HUMAN, player, chamber, 140, 20, 20} {}

Human::~Human() {}
