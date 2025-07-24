module tile;

import enums;
import entity;


Tile::Tile(TileType type, char symbol, int colour, Position pos)
    : Entity{symbol, colour, pos}, type{type} {
    entity = EntityType::TILE;
}

Tile::~Tile() {}

TileType Tile::getTileType() { return type;  }
