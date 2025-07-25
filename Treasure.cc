export module treasure;

import <memory>;
import item;
import player;
import position;
import enums;

export class Treasure : public Item {
protected:
    int value; 
    TreasureType type;
public:
    explicit Treasure(int value, Position pos);
    // return the value of the treasure
    int getValue() const;

    // returns the type of treasure
    TreasureType getTreasureType() const;

    // apply the effect of the treasure to the player, player gains gold.
    std::unique_ptr<Player> applyEffect(std::unique_ptr<Player> player) override;
    virtual ~Treasure() = default;
};

export class SmallPile : public Treasure {
public:
    explicit SmallPile(Position pos);
};

export class NormalPile : public Treasure {
public:
    explicit NormalPile(Position pos);
};

export class MerchantHoard : public Treasure {
public:
    explicit MerchantHoard(Position pos);
};

export class DragonHoard : public Treasure {
public:
    explicit DragonHoard(Position pos);
};
