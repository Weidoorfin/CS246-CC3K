module potionfactory;

import <memory>;
import concretepotion;
import potion;
import position;
import enums;

static std::unique_ptr<Potion> PotionFactory::createPotion(PotionType type, Position pos) {
    switch(type) {
        case PotionType::RH:
            return std::make_unique<RedPotion>(pos);
        case PotionType::BA:
            return std::make_unique<BluePotion>(pos);
        case PotionType::PH:
            return std::make_unique<PotionOfHealing>(pos);
        case PotionType::WA:
            return std::make_unique<PotionOfWealth>(pos);
    }
}