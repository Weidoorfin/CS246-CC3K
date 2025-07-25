export module player;

import <string>;
import <memory>;
import <cmath>;
import enums;
import character;
import position;

export class Player : public Character {
    int Gold;
  protected:
    int totGold; // amount gold obtained in total
  public:
    Player(Race race, int maxHP, int atk, int def, Position pos);
    virtual ~Player() = default;
    virtual int getGold() const;
    virtual double getScore() const;
    virtual void gainGold(int amount);
    virtual void onTurn();
    virtual void loseHP(int dec);
    virtual void gainHP(int inc);
    virtual void attack(Character &target) override;
    virtual void onHit(Character &whoFrom) override; // Handle the hit logic
    virtual double getPotionMultiplier() const;
    virtual std::string getRaceName() const = 0;
    virtual int getCurrentHP() const;


    virtual std::unique_ptr<Player> reset() const = 0;
    virtual std::unique_ptr<Player> applyEffect(std::unique_ptr<Player> player);
};


