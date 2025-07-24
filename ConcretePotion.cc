export module concretepotion;

import <memory>;
import potion;
import enums;
import position;
import player;

export class RH : public Potion {
public:
    RH(Position pos = Position{0, 0});
    std::unique_ptr<Player> applyEffect(std::unique_ptr<Player> player) override;
};

export class PH : public Potion {
public:
    PH(Position pos = Position{0, 0});
    std::unique_ptr<Player> applyEffect(std::unique_ptr<Player> player) override;
};

export class BA : public Potion {
public:
    BA(Position pos = Position{0, 0});
    std::unique_ptr<Player> applyEffect(std::unique_ptr<Player> player) override;
};

export class BD : public Potion {
public:
    BD(Position pos = Position{0, 0});
    std::unique_ptr<Player> applyEffect(std::unique_ptr<Player> player) override;
};

export class WA : public Potion {
public:
    WA(Position pos = Position{0, 0});
    std::unique_ptr<Player> applyEffect(std::unique_ptr<Player> player) override;
};

export class WD : public Potion {
public:
    WD(Position pos = Position{0, 0});
    std::unique_ptr<Player> applyEffect(std::unique_ptr<Player> player) override;
};
