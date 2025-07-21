module treasure;

import item;
import entity;
import player;
import enums;

Treasure::Treasure(int value) : value{value} {
    entity = EntityType::TREASURE; // Set the entity type to TREASURE
}

int Treasure::getValue() const {
    return value;
}

std::unique_ptr<Player> Treasure::applyEffect(std::unique_ptr<Player> player) {
    player->gainGold(value);
    return player;
}


SmallPile::SmallPile() : Treasure(1) {}

NormalPile::NormalPile() : Treasure(2) {}

MerchantHoard::MerchantHoard() : Treasure(4) {}

DragonHoard::DragonHoard() : Treasure(6) {}