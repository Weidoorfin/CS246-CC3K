export module character;

import entity;
import enums;

export class Character: public Entity {
    int maxHP, atk, def;
  protected:
    int currentHP;
  public:
    Character();
    virtual ~Character() = 0;
    int getAtk() const;
    int getDef() const;
    int getMaxHP() const;
    bool isAlive() const;
    void move(Direction dir);
    void onHit(Character &whoFrom);
};
