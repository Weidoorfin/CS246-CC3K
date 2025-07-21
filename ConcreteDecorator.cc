export module concretedecorator;

import potiondecorator;

export class BAEff : public PotionDecorator {
public:
    BAEff(std::unique_ptr<Player> wrapped);
    int getAtk() const override;
};

export class BDEff : public PotionDecorator {
public:
    BDEff(std::unique_ptr<Player> wrapped);
    int getDef() const override;
};

export class WAEff : public PotionDecorator {
public:
    WAEff(std::unique_ptr<Player> wrapped);
    int getAtk() const override;
};

export class WDEff : public PotionDecorator {
public:
    WDEff(std::unique_ptr<Player> wrapped);
    int getDef() const override;
};
