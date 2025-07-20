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
    void tilevalid(Position pos) const; // returns true if the tile is an valid tile
};

