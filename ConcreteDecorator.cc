export module concretedecorator;

import <memory>;
import player;
import potion;
import potiondecorator;
import character;

export class BAEff : public PotionDecorator {
public:
    BAEff(std::unique_ptr<Player> wrapped);
    int getAtk() const override;
    std::unique_ptr<Player> applyEffect(std::unique_ptr<Player> player) override;
};

export class BDEff : public PotionDecorator {
public:
    BDEff(std::unique_ptr<Player> wrapped);
    int getDef() const override;
    std::unique_ptr<Player> applyEffect(std::unique_ptr<Player> player) override;
};

export class WAEff : public PotionDecorator {
public:
    WAEff(std::unique_ptr<Player> wrapped);
    int getAtk() const override;
    std::unique_ptr<Player> applyEffect(std::unique_ptr<Player> player) override;
};

export class WDEff : public PotionDecorator {
public:
    WDEff(std::unique_ptr<Player> wrapped);
    int getDef() const override;
    std::unique_ptr<Player> applyEffect(std::unique_ptr<Player> player) override;
};
