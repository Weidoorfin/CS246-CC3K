export module character;

import entity;
import enums;

export class Character: public Entity {
    int maxHP, atk, def;
    Chamber &chamber; // reference to the chamber
  protected:
    int currentHP;
  public:
    Character(Chamber &chamber, int maxHP, int atk, int def);
    virtual ~Character() = 0;
    int getAtk() const;
    int getDef() const;
    int getMaxHP() const;
    bool isAlive() const;
    Chamber &getChamber() const;
    bool move(Direction dir); // will return false if the move is invalid, and will not move the character

    // virtual because some enemy need to override onHit to add custom logic
    virtual void onHit(Character &whoFrom);
};
