// export module enemy;

// import enums;
// import character;
// import subject;
// import observer;
// import position;
// import chamber;

#ifndef ENEMY_H
#define ENEMY_H

#include "Enums.h"
#include "Character.h"
#include "Subject.h"
#include "Observer.h"
#include "Position.h"
#include "Chamber.h"

export class Enemy: public Character, public Observer {
    EnemyType Type;
  public:
    virtual void automove() = 0;
    virtual int dropGold() = 0;
    virtual bool isHostile() const = 0;
    virtual void setHostile(bool hostile) = 0;
    virtual bool isInRange(Position pos) const = 0;
    virtual Chamber getChamber() = 0;
    virtual update(Subject Subject) = 0;
};

#endif
