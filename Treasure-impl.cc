module treasure;

import <memory>;
import enums;
import position;
import item;
import player;


Treasure::Treasure(int value, Position pos)
    : Item{'G', 0, pos}, value{value} {
    entity = EntityType::TREASURE; // Set the entity type to TREASURE
}

int Treasure::getValue() const {
    return value;
}

std::unique_ptr<Player> Treasure::applyEffect(std::unique_ptr<Player> player) {
    player->gainGold(value);
    return player;
}


SmallPile::SmallPile(Position pos) : Treasure(1, pos) {}

NormalPile::NormalPile(Position pos) : Treasure(2, pos) {}

MerchantHoard::MerchantHoard(Position pos) : Treasure(4, pos) {}

DragonHoard::DragonHoard(Position pos) : Treasure(6, pos) {}