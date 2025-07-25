export module potionfactory;

import <memory>;
import concretepotion;
import potion;
import position;
import enums;

export class PotionFactory {
public:
    // Creates a potion of the specified type. 
    static std::unique_ptr<Potion> createPotion(PotionType type, Position pos);
};
