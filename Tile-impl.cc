module tile;

import entity;

Tile::Tile(TileType type, Position pos)
    : Entity{' ', 0, pos}, type{type} {
    switch(type) {
        case TileType::VerticalWall:
            
        
        case TileType::HorizontalWall:
        case TileType::Floor:
        case TileType::Stair:
        case TileType::Door:
        case TileType::Nothing:
        case TileType::Corridor:
            break; // No additional initialization needed for these types
    }
    entity = EntityType::TILE; // Set the entity type to TILE
}