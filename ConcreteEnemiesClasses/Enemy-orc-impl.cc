module orc;

import enemy;
import chamber;
import enums;

Orc::Orc(Player &player, Chamber &chamber)
    : Enemy{EnemyType::ORC, player, chamber, 180, 30, 25} {}

Orc::~Orc() {}
