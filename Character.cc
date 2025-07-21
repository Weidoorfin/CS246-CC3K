export module character;

import entity;
import enums;

export class Character: public Entity {
    int maxHP, atk, def;
    Race race;
  protected:
    int currentHP;
  public:
    Character(Race race, int maxHP, int atk, int def, char symbol, int colour, Position pos);
    virtual ~Character() = 0;
    virtual int getAtk() const;
    virtual int getDef() const;
    virtual int getMaxHP() const;
    Race getRace() const;
    bool isAlive() const;
    virtual bool move(Direction dir); // will return false if the move is invalid, and will not move the character
    virtual void attack(Character &target); // Handle the attack logic
    virtual void onHit(Character &whoFrom); // Handle the hit logic
};
