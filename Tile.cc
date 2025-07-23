export module tile;

import enums;
import position;
import entity;

export class Tile : public Entity {
    TileType type;
  public:
    Tile(TileType type, Position pos);
};
