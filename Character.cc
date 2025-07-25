export module character;

import enums;
import position;
import entity;

export class Character: public Entity {
    Race race;
    int maxHP, atk, def;
  protected:
    int currentHP;
  public:
    Character(Race race, int maxHP, int atk, int def, char symbol, int colour, Position pos);
    virtual ~Character() = 0;
    virtual int getAtk() const;
    virtual int getDef() const;
    virtual int getMaxHP() const;
    virtual Race getRace() const;
    bool isAlive() const;
    virtual void move(Direction dir);
    virtual void attack(Character &target); // Handle the attack logic
    virtual void onHit(Character &whoFrom); // Handle the hit logic
    int getcurrentHP() const { return currentHP; } // cerr DEBUG
};
