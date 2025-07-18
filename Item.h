// export module item;

// import <memory>;
// import entity;

#ifndef ITEM_H
#define ITEM_H

#include <memory>

#include "Entity.h"

export class Item: public Entity {
  public:
    virtual void use();
    virtual unique_ptr<Item> RandomPotion();
    virtual unique_ptr<Item> RandomTreasure();
};

#endif
