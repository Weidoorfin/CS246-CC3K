module treasurefactory;

import <memory>;
import treasure;
import position;
import enums;

std::unique_ptr<Treasure> TreasureFactory::createTreasure(TreasureType type, Position pos) {
    switch (type) {
        case TreasureType::SMALL:
            return std::make_unique<SmallPile>(pos);
        case TreasureType::NORMAL:
            return std::make_unique<NormalPile>(pos);
        case TreasureType::MERCHANT:
            return std::make_unique<MerchantHoard>(pos);
        case TreasureType::DRAGON:
            return std::make_unique<DragonHoard>(pos);
        default:
            throw;
    }
}
