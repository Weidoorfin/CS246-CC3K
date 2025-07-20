module dragon;

import enemy;
import chamber;
import enums;

Dragon::Dragon(Player &player, Chamber &chamber)
    : Enemy{EnemyType::DRAGON, player, chamber, 150, 20, 20} {}

Dragon::~Dragon() {}