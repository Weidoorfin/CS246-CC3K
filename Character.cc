export module character;

import enums;
import position;
import entity;

// Abstract Character class, inherit from entity. Will store Race, maxHP, atk, def 
// (data related to character)
export class Character: public Entity {
    Race race;
    int maxHP, atk, def;
  protected:
    int currentHP;
  public:
    Character(Race race, int maxHP, int atk, int def, char symbol, int colour, Position pos);
    virtual ~Character() = 0;

    // return true if character is alive
    bool isAlive() const;
    // The methods below can be overwritten by the subclasses in order to add special effects
    // Return atk of the Character
    virtual int getAtk() const;
    // return def of the character
    virtual int getDef() const;
    // return maxhp of the character
    virtual int getMaxHP() const;
    // return Race of the chraacter
    virtual Race getRace() const;
    // will change character's position to the new position indicated by dir.
    // assumes the new Position is valid for the floor
    virtual void move(Direction dir);
    // Double dispatch pattern, will automatically determine damage and HP deduction
    // based on each other's def and atk
    virtual void attack(Character &target); // Handle the attack logic
    virtual void onHit(Character &whoFrom); // Handle the hit logic
};
