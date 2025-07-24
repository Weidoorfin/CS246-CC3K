module potionfactory;

import <memory>;
import concretepotion;
import potion;
import position;
import enums;

std::unique_ptr<Potion> PotionFactory::createPotion(PotionType type, Position pos) {
    switch(type) {
        case PotionType::RH:
            return std::make_unique<RH>(pos);
        case PotionType::BA:
            return std::make_unique<BA>(pos);
        case PotionType::PH:
            return std::make_unique<PH>(pos);
        case PotionType::WA:
            return std::make_unique<WA>(pos);
        case PotionType::BD:
            return std::make_unique<BD>(pos);
        case PotionType::WD:
            return std::make_unique<WD>(pos);
        default:
            throw std::invalid_argument("Unsupported Potion type");
    }
}