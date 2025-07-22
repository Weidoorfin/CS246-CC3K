export module player;

import <memory>;
import enums;
import character;

export class Player : public Character {
    int Gold;
    int totGold; // amount gold obtained in total
  public:
    Player(PlayerRace race, int maxHP, int atk, int def, Position pos);
    virtual ~Player() = default;
    virtual int getGold() const;
    virtual double getScore() const;
    void gainGold(int amount);
    virtual void onTurn() = 0;
    virtual void loseHP(int dec);
    virtual void gainHP(int inc);
    virtual void useItem(Item &item);
    virtual void attack(Character &target) override;
    virtual void onHit(Character &whoFrom) override; // Handle the hit logic
    virtual double getPotionMultiplier() const;


    virtual std::unique_ptr<Player> reset() const = 0;
    virtual std::unique_ptr<Player> applyEffect(std::unique_ptr<Player> player) const = 0;
};


