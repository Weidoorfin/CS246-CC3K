export module tilefactory;

import <memory>;
import tile;
import position;
import enums;
import entity;

export class TileFactory {
public:
    // Create a tile with given type and pos
    static std::unique_ptr<Tile> createTile(TileType type, Position pos);
};
