export module floor;

import <vector>;

import chamber;
import enemy;
import item;
import position;


export class Floor {
    vector<Chamber> Chambers;
    vector<Enemy> enemies;
    vector<Item> items;
    Position stair;
};
