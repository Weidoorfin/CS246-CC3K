module floor;

import <fstream>;
import <vector>;

import enums;
import chamber;
import enemy;
import item;
import position;
import abstractos;
import entity;
import textdisplay;
import player;
import enemyfactory;

void Floor::getEmptyMap(std::istream &is) {
    // Implementation for reading an empty map from the input stream
    // This will populate the grid and tileTypes with initial values
    string line;
    while (getline(is, line)) {
        vector<TileType> row;
        for (char c : line) {
            switch (c) {
                case '-': 
                    row.push_back(TileType::HorizontalWall);
                    grid.push_back(nullptr);
                    break;
                case '|': 
                    row.push_back(TileType::VerticalWall);
                    grid.push_back(nullptr);
                    break;
                case '.':  
                    row.push_back(TileType::Floor);
                    grid.push_back(nullptr);
                    break;
                case '+': 
                    row.push_back(TileType::Door);
                    grid.push_back(nullptr);
                    break;
                case '#': 
                    row.push_back(TileType::Corridor);
                    grid.push_back(nullptr);
                    break;
                default: 
                    row.push_back(TileType::Nothing);
                    grid.push_back(nullptr);
                    break;
            }
        }
        tileTypes.push_back(row);
    }
}

void Floor::GeneratePlayer() {
    // Implementation for generating the player on the floor
}

void Floor::GenerateStairs() {
    // Implementation for generating stairs on the floor
}

void Floor::GenerateEntities() {
    // Implementation for generating entities (enemies, items) on the floor
}

void Floor::readFromStream(std::istream &is) {
    string line;
    int x = 0;
    while (getline(is, line)) {
        vector<TileType> row;
        vector<Entity*> gridRow; // Store entities in the grid
        int y = 0;
        for (char c : line) {
            Position pos{x, y};
            switch (c) {
                case '-': 
                    row.push_back(TileType::HorizontalWall);
                    gridRow.push_back(nullptr);
                    break;
                case '|': 
                    row.push_back(TileType::VerticalWall);
                    gridRow.push_back(nullptr);
                    break;
                case '.':  
                    row.push_back(TileType::Floor);
                    gridRow.push_back(nullptr);
                    break;
                case '+': 
                    row.push_back(TileType::Door);
                    gridRow.push_back(nullptr);
                    break;
                case '#': 
                    row.push_back(TileType::Corridor);
                    gridRow.push_back(nullptr);
                    break;
                case '/': 
                    row.push_back(TileType::Stair);
                    gridRow.push_back(nullptr);
                    stairs.push_back(pos);
                    break;
                // Handle generated entities
                case '@': 
                    row.push_back(TileType::Player);
                    gridRow.push_back(nullptr);
                    break;
                case 'H':
                    row.push_back(TileType::Enemy);
                    enemies.push_back(createEnemy(EnemyType::Human, pos));
                    gridRow.push_back(enemies.back().get());
                    break;
                case 'W':
                    row.push_back(TileType::Enemy);
                    enemies.push_back(createEnemy(EnemyType::Dwarf, pos));
                    gridRow.push_back(enemies.back().get());
                    break;
                case 'E':
                    row.push_back(TileType::Enemy);
                    enemies.push_back(createEnemy(EnemyType::Elf, pos));
                    gridRow.push_back(enemies.back().get());
                    break;
                case 'O':
                    row.push_back(TileType::Enemy);
                    enemies.push_back(createEnemy(EnemyType::Orcs, pos));
                    gridRow.push_back(enemies.back().get());
                    break;
                case 'M':
                    row.push_back(TileType::Enemy);
                    enemies.push_back(createEnemy(EnemyType::Merchant, pos));
                    gridRow.push_back(enemies.back().get());
                    break;
                case 'D':
                    row.push_back(TileType::Enemy);
                    enemies.push_back(createEnemy(EnemyType::Dragon, pos));
                    gridRow.push_back(enemies.back().get());
                    break;
                case 'L':
                    row.push_back(TileType::Enemy);
                    enemies.push_back(createEnemy(EnemyType::Halfling, pos));
                    gridRow.push_back(enemies.back().get());
                    break;
                // Handle items
                case '0':
                    row.push_back(TileType::Potion);
                    items.push_back(createItem(ItemType::RH, pos));
                    gridRow.push_back(items.back().get());
                    break;
                case '1':
                    row.push_back(TileType::Potion);
                    items.push_back(createItem(ItemType::BA, pos));
                    gridRow.push_back(items.back().get());
                    break;
                case '2':
                    row.push_back(TileType::Potion);
                    items.push_back(createItem(ItemType::BD, pos));
                    gridRow.push_back(items.back().get());
                    break;
                case '3':
                    row.push_back(TileType::Potion);
                    items.push_back(createItem(ItemType::PH, pos));
                    gridRow.push_back(items.back().get());
                    break;
                case '4':
                    row.push_back(TileType::Potion);
                    items.push_back(createItem(ItemType::WA, pos));
                    gridRow.push_back(items.back().get());
                    break;
                case '5':
                    row.push_back(TileType::Potion);
                    items.push_back(createItem(ItemType::WD, pos));
                    gridRow.push_back(items.back().get());
                    break;
                case '6':
                    row.push_back(TileType::Gold);
                    items.push_back(createItem(ItemType::Gold, pos));
                    gridRow.push_back(items.back().get());
                    break;
                case '7':
                    row.push_back(TileType::Gold);
                    items.push_back(createItem(ItemType::Treasure, pos));
                    gridRow.push_back(items.back().get());
                    break;
                case '8':
                    row.push_back(TileType::Gold);
                    items.push_back(createItem(ItemType::Treasure, pos));
                    gridRow.push_back(items.back().get());
                    break;
                case '9':
                    row.push_back(TileType::Gold);
                    items.push_back(createItem(ItemType::Treasure, pos));
                    gridRow.push_back(items.back().get());
                    break;
                // Default case for unrecognized characters
                default: 
                    row.push_back(TileType::Nothing);
                    gridRow.push_back(nullptr); 
                    break;
            } // switch (c)
            y++;
        } // for (char c : line)
        grid.push_back(gridRow);
        tileTypes.push_back(row);
        x++;
    } // while (getline(is, line))
}

Floor::Floor(){
    // Initialize the grid with empty chambers
    ifstream emptyMap("emptyfloor.txt");
    getEmptyMap(emptyMap);
    GeneratePlayer();
    GenerateStairs();
    GenerateEntities();
    notifyObservers(); // Notify observers that the floor has been initialized
}

Floor::Floor(std::istream &is) {
    readFromStream(is);
    notifyObservers(); // Notify observers that the floor has been initialized
}

Floor::Floor(std::istream &is, int seed) {
    readFromStream(is);
    // Set the random seed for the floor
    notifyObservers(); // Notify observers that the floor has been initialized
}

void Floor::setPlayer(std::unique_ptr<Player> p) {
    player = std::move(p);
}



bool Floor::isComplete() const {
    return complete;
}


// enemy具体的attack和move的逻辑（比如merchant非hostile时不攻击，dragon不移动）由method override来实现，
// floor只要满足条件就call attack和move。
//////////////////////////////////////////////////////////////
// Some previously-implemented enemy methods to make reference to:
import <random>;
import <algorithm>;
import <chrono>;
// Helper function to generate a random vector of unique directions
// this random array can be used in randomMove to try moving in a random direction
// until a valid move is found.
vector<Direction> genDirections() {
    std::vector<Direction> directions {
        Direction::N, Direction::NE, Direction::E, Direction::SE,
        Direction::S, Direction::SW, Direction::W, Direction::NW
    };
    // default time-based seed
    uint32_t seed = std::chrono::system_clock::now().time_since_epoch().count();
    // Set seed to global seed variable if it exists
    if (global_seed != 0) {
        seed = global_seed;
    }
    std::default_random_engine rng{seed};
    std::shuffle(directions.begin(), directions.end(), rng);
    return directions; // return a random direction
}

Enemy::randomMove() {
    std::vector<Direction> possibleMoves = genDirections();
    for (const Direction &dir : possibleMoves) {
        if (move(dir)) {
            return; // if the move is valid, return
        }
    }
}

Enemy::isInRange(Position pos) const {
    // Check if the position is within the range of the enemy
    return (pos.x >= pos.x - 1 && pos.x <= pos.x + 1 &&
            pos.y >= pos.y - 1 && pos.y <= pos.y + 1);
}

Enemy::update() {
    // Default implementation: random move if the player is not in range
    if (!isInRange(player.getPos())) {
        randomMove();
    } else {
        // If the player is in range, attack the player
        attack();
    }
}
//////////////////////////////////////////////////////
