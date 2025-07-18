// export module floor;

// import <vector>;

// import chamber;
// import enemy;
// import item;
// import position;

#ifndef FLOOR_H
#define FLOOR_H

#include <vector>
#include "Enemy.h"
#include "Item.h"
#include "Position.h"

export class Floor {
    vector<Chamber> Chambers;
    vector<Enemy> enemies;
    vector<Item> items;
    Position stair;
};

#endif
