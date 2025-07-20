export module potion;

import enums;


export class Potion {
    PotionType Type;
public:
    virtual ~Potion() = default;

    virtual std::unique_ptr<Player> usePotion(std::unique_ptr<Player> player) const = 0;
};