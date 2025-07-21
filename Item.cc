export module item;

import <memory>;
import entity;
import player;

export class Item {
public:
    virtual ~Item() = default;
    virtual std::unique_ptr<Player> applyEffect(std::unique_ptr<Player> player) = 0;

};
