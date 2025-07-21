export module potion;

import item;
import enums;

export class Potion : public Item {
public:
    Potion(Position pos);
    virtual ~Potion() = default;
    virtual std::unique_ptr<Player> applyEffect(std::unique_ptr<Player> player) const = 0;
};
