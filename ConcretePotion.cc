export module concretepotion;

import potion;

export class RH : public Potion {
public:
    std::unique_ptr<Player> applyEffect(std::unique_ptr<Player> player) const override;
};

export class PH : public Potion {
public:
    std::unique_ptr<Player> applyEffect(std::unique_ptr<Player> player) const override;
};

export class BA : public Potion {
public:
    std::unique_ptr<Player> applyEffect(std::unique_ptr<Player> player) const override;
};

export class BD : public Potion {
public:
    std::unique_ptr<Player> applyEffect(std::unique_ptr<Player> player) const override;
};

export class WA : public Potion {
public:
    std::unique_ptr<Player> applyEffect(std::unique_ptr<Player> player) const override;
};

export class WD : public Potion {
public:
    std::unique_ptr<Player> applyEffect(std::unique_ptr<Player> player) const override;
};