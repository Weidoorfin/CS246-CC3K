export module chamber;

import <vector>;
import position;

class Chamber {
    int id;
    vector<vector<char>> validArea;
  public:
    bool contains(Position pos) const;
    Position getRamdomFloorTile() const;
    bool isFloorTile(Position pos) const;
};

