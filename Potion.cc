export module potion;

import enums;


export class Potion {
    PotionType Type;
public:
    virtual ~Potion() = default;

    virtual void applyEffect(Player &player) const = 0;
};