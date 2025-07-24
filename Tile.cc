export module tile;

import enums;
import position;
import entity;

export class Tile : public Entity {
    TileType type;
  public:
    Tile(TileType type, char symbol, int colour, Position pos);
    virtual ~Tile() = 0;
    TileType getTileType();
};
