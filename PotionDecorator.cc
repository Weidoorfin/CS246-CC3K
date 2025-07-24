export module potiondecorator;

import <memory>;
import player;
import character;
import enums;

export class PotionDecorator : public Player {
protected:
    std::unique_ptr<Player> base;

public:
    PotionDecorator(std::unique_ptr<Player> wrapped);
    virtual ~PotionDecorator() = default;
    virtual Race getRace() const override;
    virtual int getAtk() const override;
    virtual int getDef() const override;
    virtual int getGold() const override;
    virtual double getScore() const override;
    virtual int getMaxHP() const override;
    virtual void gainGold(int amount) override;
    virtual void onTurn() override;

    virtual void gainHP(int inc) override;
    virtual void loseHP(int dec) override;
    virtual void attack(Character &target) override;
    virtual void onHit(Character &whoFrom) override;
    virtual double getPotionMultiplier() const override;
    virtual std::string getRaceName() const override;
    virtual int getCurrentHP() const override;

    virtual std::unique_ptr<Player> reset() const override;
    virtual std::unique_ptr<Player> applyEffect(std::unique_ptr<Player> player) override;
};
