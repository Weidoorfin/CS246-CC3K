export module treasure;

import item;

export class Treasure : public Item {
protected:
    int value; // Amount of gold this treasure is worth
public:
    Treasure(int value);
    int getValue() const;
    std::unique_ptr<Player> applyEffect(std::unique_ptr<Player> player) override;
    virtual ~Treasure() = default;
};

export class SmallPile : public Treasure {
public:
    SmallPile();
};

export class NormalPile : public Treasure {
public:
    NormalPile();
};

export class MerchantHoard : public Treasure {
public:
    MerchantHoard();
};

export class DragonHoard : public Treasure {
public:
    DragonHoard();
};