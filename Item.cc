export module item;

import <memory>;
import entity;

export class Item: public Entity {
  public:
    void use();
    // virtual unique_ptr<Item> RandomPotion();
    // virtual unique_ptr<Item> RandomTreasure();
};

