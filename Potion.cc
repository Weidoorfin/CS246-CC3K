export module potion;

import <memory>;
import item;
import enums;
import position;
import player;

export class Potion : public Item {
    PotionType type;
public:
    Potion(PotionType type, Position pos);
    virtual ~Potion() = default;
    virtual std::unique_ptr<Player> applyEffect(std::unique_ptr<Player> player) override;
};
