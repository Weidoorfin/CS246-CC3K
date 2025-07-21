module treasure;

import item;

Treasure::Treasure(int value) : value{value} {}

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