export module treasure;

import <memory>;
import item;
import player;
import position;
import enums;

export class Treasure : public Item {
protected:
    int value; // Amount of gold this treasure is worth
    TreasureType type; // Type of treasure
public:
    explicit Treasure(int value, Position pos);
    int getValue() const;
    TreasureType getTreasureType() const;
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