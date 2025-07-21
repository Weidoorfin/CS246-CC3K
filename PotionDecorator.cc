export module potiondecorator;

import player;
import <memory>;

export class PotionDecorator : public Player {
protected:
    std::unique_ptr<Player> base;

public:
    PotionDecorator(std::unique_ptr<Player> wrapped);

    virtual int getAtk() const override;
    virtual int getDef() const override;
    virtual int getGold() const override;
    virtual int getTotGold() const override;
    virtual int getMaxHP() const override;
    virtual int getHP() const override;

    virtual void onKill() override;
    virtual void onTurn() override;

    virtual void gainHP(int inc) override;
    virtual void loseHP(int dec) override;


    std::unique_ptr<Player> reset() override;
    std::unique_ptr<Player> PotionDecorator::usePotion(const Potion &potion) override;
};
