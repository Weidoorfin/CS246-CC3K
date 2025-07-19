export module character;

import entity;
import enums;

export class Character: public Entity {
    int MaxHP, Atk, Def;
  protected:
    int CurrentHP;
  public:
    int getAtk();
    int getDef();
    int getMaxHP();
    void move(Direction dir);
    bool isAlive();
    void onHit(Character &whoFrom);
    virtual ~Character() = 0;
};
