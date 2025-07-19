// export module character;

// import entity;
// import enums;

#ifndef CHARACTER_H
#define CHARACTER_H

#include "Entity.h"
#include "Enums.h"

export class Character: public Entity {
  protected:
    int CurrentHP, MaxHP, Atk, Def;
  public:
    virtual void Attack(Direction dir) = 0;
    virtual void Defence(Direction dir) = 0;
    virtual void onHit(Character &whoFrom) = 0;
    virtual void Move(Direction dir);
    virtual bool isAlive() const = 0;
};

#endif
