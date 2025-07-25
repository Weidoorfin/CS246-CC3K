export module potiondecorator;

import <memory>;
import player;
import character;
import enums;


/// Decorator class that adds potion effects to a Player.
export class PotionDecorator : public Player {
protected:
    std::unique_ptr<Player> base;

public:
    /// Constructs a PotionDecorator wrapping the given Player.
    PotionDecorator(std::unique_ptr<Player> wrapped);
    /// Default destructor.
    virtual ~PotionDecorator() = default;

    // Overrides all player interface methods, methods are all 
    //   with respect to the base player
    /// Returns the decorated player's race.
    virtual Race getRace() const override;
    /// Returns the decorated player's attack value.
    virtual int getAtk() const override;
    /// Returns the decorated player's defense value.
    virtual int getDef() const override;
    /// Returns the decorated player's current gold.
    virtual int getGold() const override;
    /// Returns the decorated player's score.
    virtual double getScore() const override;
    /// Returns the decorated player's maximum HP.
    virtual int getMaxHP() const override;
    /// Increases the decorated player's gold by the given amount.
    virtual void gainGold(int amount) override;
    /// Called at the start of the decorated player's turn.
    virtual void onTurn() override;

    /// Increases the decorated player's HP by the given amount.
    virtual void gainHP(int inc) override;
    /// Decreases the decorated player's HP by the given amount.
    virtual void loseHP(int dec) override;
    /// Delegates attack to the decorated player.
    virtual void attack(Character &target) override;
    /// Handles logic when the decorated player is hit.
    virtual void onHit(Character &whoFrom) override;
    /// Returns the potion multiplier applied to the player.
    virtual double getPotionMultiplier() const override;
    /// Returns the name of the decorated player's race.
    virtual std::string getRaceName() const override;
    /// Returns the decorated player's current HP.
    virtual int getCurrentHP() const override;

    /// Creates a fresh copy of the decorated player.
    virtual std::unique_ptr<Player> reset() const override;
    /// Applies the potion effect to the given player instance, return a decorated instance
    virtual std::unique_ptr<Player> applyEffect(std::unique_ptr<Player> player) override;
};
