module potion;

import <memory>;
import item;
import enums;
import position;
import player;

Potion::Potion(PotionType type, Position pos)
    : Item{'P', 184, pos}, type{type} {
    entity = EntityType::POTION; // Set the entity type to POTION
}
