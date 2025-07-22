export module potionfactory;

import <memory>;
import concretepotion;
import potion;
import position;
import enums;

export class PotionFactory {
public:
    static std::unique_ptr<Potion> createPotion(PotionType type, Position pos);
};
