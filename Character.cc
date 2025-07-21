export module character;

import entity;
import enums;

export class Character: public Entity {
    int maxHP, atk, def;
  protected:
    int currentHP;
  public:
    Character(int maxHP, int atk, int def);
    virtual ~Character() = 0;
    virtual int getAtk() const;
    virtual int getDef() const;
    virtual int getMaxHP() const;
    bool isAlive() const;
    bool move(Direction dir); // will return false if the move is invalid, and will not move the character

    // virtual because some enemy need to override onHit to add custom logic
    virtual void onHit(Character &whoFrom);
};
