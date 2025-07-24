module tilefactory;

import <memory>;
import tile;
import position;
import enums;
import entity;
import concretetiles;

std::unique_ptr<Tile> TileFactory::createTile(TileType type, Position pos) {
    switch(type) {
        case TileType::VerticalWall:
            return std::make_unique<VerticalWall>(pos);
        case TileType::HorizontalWall:
            return std::make_unique<HorizontalWall>(pos);
        case TileType::Floor:
            return std::make_unique<Floor>(pos);
        case TileType::Stair:
            return std::make_unique<Stair>(pos);
        case TileType::Door:
            return std::make_unique<Door>(pos);
        case TileType::Nothing:
            return std::make_unique<Nothing>(pos);
        case TileType::Corridor:
            return std::make_unique<Corridor>(pos);
        default:
            throw std::invalid_argument("Unknown TileType");
    }
}
