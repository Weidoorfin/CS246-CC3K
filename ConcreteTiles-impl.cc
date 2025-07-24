module concretetiles;

import enums;
import tile;
import position;

Nothing::Nothing(Position pos)
    : Tile{TileType::Nothing, ' ', 0, pos} {}

HorizontalWall::HorizontalWall(Position pos)
    : Tile{TileType::HorizontalWall, '-', 0, pos} {}

VerticalWall::VerticalWall(Position pos)
    : Tile{TileType::VerticalWall, '|', 0, pos} {}

Floor::Floor(Position pos)
    : Tile{TileType::Floor, '.', 0, pos} {}

Stair::Stair(Position pos)
    : Tile{TileType::Stair, '\\', 0, pos} {}

Door::Door(Position pos)
    : Tile{TileType::Door, '+', 0, pos} {}

Corridor::Corridor(Position pos)
    : Tile{TileType::Corridor, '#', 0, pos} {}

