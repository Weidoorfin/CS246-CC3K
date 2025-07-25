export module item;

import <memory>;
import entity;
import player;
import position;

export class Item : public Entity {
    // Items can be used by players to apply effects
public:
    Item(char symbol, int colour, Position pos);
    virtual ~Item() = default;

    // apply the effect of this item to player
    virtual std::unique_ptr<Player> applyEffect(std::unique_ptr<Player> player) = 0;

};
