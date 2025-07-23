module treasurefactory;

import <memory>;
import treasure;
import position;
import enums;

std::unique_ptr<Treasure> TreasureFactory::createTreasure(TreasureType type) {
    switch (type) {
        case TreasureType::SMALL:
            return std::make_unique<SmallTreasure>();
        case TreasureType::NORMAL:
            return std::make_unique<NormalTreasure>();
        case TreasureType::MERCHANT:
            return std::make_unique<MerchantTreasure>();
        case TreasureType::DRAGON:
            return std::make_unique<DragonTreasure>();
    }
}
