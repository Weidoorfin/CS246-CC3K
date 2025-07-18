export module character;

import entity;
import enums;

export class Character: public Entity {
  protected:
    int CurrentHP, MaxHP, Atk, Def;
  public:
    virtual void Attack(Direction dir) = 0;
    virtual void Defence(Direction dir) = 0;
    virtual void Fight(Character &whoFrom) = 0;
    virtual void Move(Direction dir);
};
