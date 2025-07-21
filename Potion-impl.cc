module potion;

import enums;
import entity;

Potion::Potion(Position pos)
    : Item{'P', 0, pos} {
    entity = EntityType::POTION; // Set the entity type to POTION
}
