export module floor;

import <vector>;

import chamber;
import enemy;
import item;
import position;
import subject;

export class Floor : public Subject {
    Position stair;
    bool complete;
    int level;
    vector<Chamber> chambers;
    vector<Enemy> enemies;
    vector<Item> items;
 public:
    void isComplete();
    void init();
};

// reading empty floor into floor
istream &operator>>(istream &is, Floor &fl);
