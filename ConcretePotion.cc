export module concretepotion;

import potion;

export class RH : public potion {
public:
    std::unique_ptr<Player> usePotion(std::unique_ptr<Player> player) const override;
};

export class PH : public potion {
public:
    std::unique_ptr<Player> usePotion(std::unique_ptr<Player> player) const override;

};

export class BA: public potion {
public:
    std::unique_ptr<Player> usePotion(std::unique_ptr<Player> player) const override;

};

export class BD: public potion {
public:
    std::unique_ptr<Player> usePotion(std::unique_ptr<Player> player) const override;

};

export class WA: public potion {
public:
    std::unique_ptr<Player> usePotion(std::unique_ptr<Player> player) const override;

};

export class WD: public potion {
public:
    std::unique_ptr<Player> usePotion(std::unique_ptr<Player> player) const override;

};


Restore health (RH): restore up to 10 HP (cannot exceed maximum prescribed by race) 
• Boost Atk (BA): increase ATK by 5
• Boost Def (BD): increase Def by 5
Negative Potions:
• Poison health (PH): lose up to 10 HP (cannot fall below 0 HP) 
• Wound Atk (WA): decrease Atk by 5
• Wound Def (WD): decrease Def by 5