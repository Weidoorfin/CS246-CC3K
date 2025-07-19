export module chamber;

import <vector>;

import position;

#ifndef CHAMBER_H
#define CHAMBER_H

#include <vector>

#include "position.h"

class Chamber {
    int id;
    vector<vector<char>> validArea;
  public:
    bool contains(Position pos) const;
    Position getRamdomFloorPile() const;
    bool isFloorPile(Position pos) const;
};

#endif
