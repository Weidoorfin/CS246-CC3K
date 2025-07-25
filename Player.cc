export module player;

import <string>;
import <memory>;
import <cmath>;
import enums;
import character;
import position;

// Player base class representing the user-controlled character in the game
export class Player : public Character {
    // Amount of gold currently held
    int Gold;

  protected:
    // amount gold obtained in total through out the game
    int totGold;

  public:
    // Constructor initializing race, stats, and position
    Player(Race race, int maxHP, int atk, int def, Position pos);

    // Virtual destructor for proper cleanup
    virtual ~Player() = 0;

    // Get the amount of gold currently held
    virtual int getGold() const;

    // Get the player's final score, adjusted by race
    virtual double getScore() const;

    // Increase gold by amount
    virtual void gainGold(int amount);

    // Called at the end of player's turn
    virtual void onTurn();

    // Decrease player's HP by dec
    virtual void loseHP(int dec);

    // Increase player's HP by inc
    virtual void gainHP(int inc);

    // Called when player attacks the target character
    virtual void attack(Character &target) override;

    // Called when the player is hit by another character
    virtual void onHit(Character &whoFrom) override;

    // Multiplier for potion effects, can vary by race
    virtual double getPotionMultiplier() const;

    // Get the name of the player's race
    virtual std::string getRaceName() const = 0;

    // Get the current HP of the player
    virtual int getCurrentHP() const;

    // Reset the player to the version before temprary potion
    virtual std::unique_ptr<Player> reset() const = 0;

    // Apply an effect, returns a new decorated Player object
    virtual std::unique_ptr<Player> applyEffect(std::unique_ptr<Player> player);
};

