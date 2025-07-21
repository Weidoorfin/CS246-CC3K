export module item;

import <memory>;
import entity;
import player;

export class Item : public Entity {
    // Items can be used by players to apply effects
public:
    virtual Item(char symbol, int colour, Position pos);
    virtual ~Item() = default;
    virtual std::unique_ptr<Player> applyEffect(std::unique_ptr<Player> player) = 0;

};
