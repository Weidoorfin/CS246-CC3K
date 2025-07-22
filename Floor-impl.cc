module floor;

import <fstream>;
import <vector>;

import enums;
import chamber;
import enemy;
import item;
import potion;
import treasure;
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
    int y = 0;
    while (getline(is, line)) {
        int x = 0;
        for (char c : line) {
            Position pos{x, y};
            switch (c) {
                case '-':
                    tiles.push_back(std::make_unique<Tile>(TileType::HorizontalWall, pos));
                    terrainRow.push_back(tiles.back().get());
                    gridRow.push_back(nullptr);
                    break;
                case '|': 
                    tiles.push_back(std::make_unique<Tile>(TileType::VerticalWall, pos));
                    terrainRow.push_back(tiles.back().get());
                    gridRow.push_back(nullptr);
                    break;
                case '.':  
                    tiles.push_back(std::make_unique<Tile>(TileType::Floor, pos));
                    terrainRow.push_back(tiles.back().get());
                    gridRow.push_back(nullptr);
                    break;
                case '+': 
                    tiles.push_back(std::make_unique<Tile>(TileType::Door, pos));
                    terrainRow.push_back(tiles.back().get());
                    gridRow.push_back(nullptr);
                    break;
                case '#': 
                    tiles.push_back(std::make_unique<Tile>(TileType::Corridor, pos));
                    terrainRow.push_back(tiles.back().get());
                    gridRow.push_back(nullptr);
                    break;
                case '/': 
                    tiles.push_back(std::make_unique<Tile>(TileType::Stair, pos));
                    terrainRow.push_back(tiles.back().get());
                    gridRow.push_back(nullptr);
                    stairs = pos;
                    break;
                // Handle generated entities
                case ' ':
                    tiles.push_back(std::make_unique<Tile>(TileType::Nothing, pos));
                    terrainRow.push_back(tiles.back().get());
                    gridRow.push_back(nullptr); 
                    break;
            x++;
        } // for (char c : line)
        terrain.pushBack(terrainRow);
        grid.push_back(gridRow);
        tileTypes.push_back(row);
        y++;
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
    int y = 0;
    while (getline(is, line)) {
        int x = 0;
        vector<Entity*> terrainRow;
        vector<Entity*> gridRow; // Store entities in the grid
        EnemyFactory ef;
        PotionFactory pf;
        TreasureFactory tf;
        for (char c : line) {
            Position pos{x, y};
            switch (c) {
                case '-':
                    tiles.push_back(std::make_unique<Tile>(TileType::HorizontalWall, pos));
                    terrainRow.push_back(tiles.back().get());
                    gridRow.push_back(nullptr);
                    break;
                case '|': 
                    tiles.push_back(std::make_unique<Tile>(TileType::VerticalWall, pos));
                    terrainRow.push_back(tiles.back().get());
                    gridRow.push_back(nullptr);
                    break;
                case '.':  
                    tiles.push_back(std::make_unique<Tile>(TileType::Floor, pos));
                    terrainRow.push_back(tiles.back().get());
                    gridRow.push_back(nullptr);
                    break;
                case '+': 
                    tiles.push_back(std::make_unique<Tile>(TileType::Door, pos));
                    terrainRow.push_back(tiles.back().get());
                    gridRow.push_back(nullptr);
                    break;
                case '#': 
                    tiles.push_back(std::make_unique<Tile>(TileType::Corridor, pos));
                    terrainRow.push_back(tiles.back().get());
                    gridRow.push_back(nullptr);
                    break;
                case '/': 
                    tiles.push_back(std::make_unique<Tile>(TileType::Stair, pos));
                    terrainRow.push_back(tiles.back().get());
                    gridRow.push_back(nullptr);
                    stairs = pos;
                    break;
                // Handle generated entities
                case ' ':
                    tiles.push_back(std::make_unique<Tile>(TileType::Nothing, pos));
                    terrainRow.push_back(tiles.back().get());
                    gridRow.push_back(nullptr); 
                    break;
                case '@': 
                    // Create player entity
                    tiles.push_back(std::make_unique<Tile>(TileType::Floor, pos));
                    terrainRow.push_back(tiles.back().get());
                    gridRow.push_back(player);
                    break;
                case 'H':
                    tiles.push_back(std::make_unique<Tile>(TileType::Floor, pos));
                    terrainRow.push_back(tiles.back().get());
                    enemies.push_back(ef.createEnemy(EnemyType::Human, pos));
                    gridRow.push_back(enemies.back().get());
                    break;
                case 'W':
                    tiles.push_back(std::make_unique<Tile>(TileType::Floor, pos));
                    terrainRow.push_back(tiles.back().get());
                    enemies.push_back(ef.createEnemy(EnemyType::Dwarf, pos));
                    gridRow.push_back(enemies.back().get());
                    break;
                case 'E':
                    tiles.push_back(std::make_unique<Tile>(TileType::Floor, pos));
                    terrainRow.push_back(tiles.back().get());
                    enemies.push_back(ef.createEnemy(EnemyType::Elf, pos));
                    gridRow.push_back(enemies.back().get());
                    break;
                case 'O':
                    tiles.push_back(std::make_unique<Tile>(TileType::Floor, pos));
                    terrainRow.push_back(tiles.back().get());
                    enemies.push_back(ef.createEnemy(EnemyType::Orcs, pos));
                    gridRow.push_back(enemies.back().get());
                    break;
                case 'M':
                    tiles.push_back(std::make_unique<Tile>(TileType::Floor, pos));
                    terrainRow.push_back(tiles.back().get());
                    enemies.push_back(ef.createEnemy(EnemyType::Merchant, pos));
                    gridRow.push_back(enemies.back().get());
                    break;
                case 'D':
                    tiles.push_back(std::make_unique<Tile>(TileType::Floor, pos));
                    terrainRow.push_back(tiles.back().get());
                    enemies.push_back(ef.createEnemy(EnemyType::Dragon, pos));
                    gridRow.push_back(enemies.back().get());
                    break;
                case 'L':
                    tiles.push_back(std::make_unique<Tile>(TileType::Floor, pos));
                    terrainRow.push_back(tiles.back().get());
                    enemies.push_back(ef.createEnemy(EnemyType::Halfling, pos));
                    gridRow.push_back(enemies.back().get());
                    break;
                case '0':
                    tiles.push_back(std::make_unique<Tile>(TileType::Floor, pos));
                    terrainRow.push_back(tiles.back().get());
                    potions.push_back(pf.createPotion(PotionType::RH, pos));
                    gridRow.push_back(potions.back().get());
                    break;
                case '1':
                    tiles.push_back(std::make_unique<Tile>(TileType::Floor, pos));
                    terrainRow.push_back(tiles.back().get());
                    potions.push_back(pf.createPotion(PotionType::BA, pos));
                    gridRow.push_back(potions.back().get());
                    break;
                case '2':
                    tiles.push_back(std::make_unique<Tile>(TileType::Floor, pos));
                    terrainRow.push_back(tiles.back().get());
                    potions.push_back(pf.createPotion(PotionType::BD, pos));
                    gridRow.push_back(potions.back().get());
                    break;
                case '3':
                    tiles.push_back(std::make_unique<Tile>(TileType::Floor, pos));
                    terrainRow.push_back(tiles.back().get());
                    potions.push_back(pf.createPotion(PotionType::PH, pos));
                    gridRow.push_back(potions.back().get());
                    break;
                case '4':
                    tiles.push_back(std::make_unique<Tile>(TileType::Floor, pos));
                    terrainRow.push_back(tiles.back().get());
                    potions.push_back(pf.createPotion(PotionType::WA, pos));
                    gridRow.push_back(potions.back().get());
                    break;
                case '5':
                    tiles.push_back(std::make_unique<Tile>(TileType::Floor, pos));
                    terrainRow.push_back(tiles.back().get());
                    potions.push_back(pf.createPotion(PotionType::WD, pos));
                    gridRow.push_back(potions.back().get());
                    break;
                case '6': // small
                    tiles.push_back(std::make_unique<Tile>(TileType::Floor, pos));
                    terrainRow.push_back(tiles.back().get());
                    treasures.push_back(tf.createTreasure(TreasureType::SMALL, pos));
                    gridRow.push_back(treasures.back().get());
                    break;
                case '7': // medium
                    tiles.push_back(std::make_unique<Tile>(TileType::Floor, pos));
                    terrainRow.push_back(tiles.back().get());
                    treasures.push_back(tf.createTreasure(TreasureType::NORMAL, pos));
                    gridRow.push_back(treasures.back().get());
                    break;
                case '8': // merchant
                    tiles.push_back(std::make_unique<Tile>(TileType::Floor, pos));
                    terrainRow.push_back(tiles.back().get());
                    treasures.push_back(tf.createTreasure(TreasureType::MERCHANT, pos));
                    gridRow.push_back(treasures.back().get());
                    break;
                case '9': // dragon
                    tiles.push_back(std::make_unique<Tile>(TileType::Floor, pos));
                    terrainRow.push_back(tiles.back().get());
                    treasures.push_back(tf.createTreasure(TreasureType::DRAGON, pos));
                    gridRow.push_back(treasures.back().get());
                    break;
                
            }
            x++;
        } // for (char c : line)
        terrain.pushBack(terrainRow);
        grid.push_back(gridRow);
        tileTypes.push_back(row);
        y++;
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

Position target(Position curr, Direction dir) {
    switch (dir) {
        case Direction::N:
            return Position{curr.x, curr.y - 1};
        case Direction::NE:
            return Position{curr.x + 1, curr.y - 1};
        case Direction::E:
            return Position{curr.x + 1, curr.y};
        case Direction::SE:
            return Position{curr.x + 1, curr.y + 1};
        case Direction::S:
            return Position{curr.x, curr.y + 1};
        case Direction::SW:
            return Position{curr.x - 1, curr.y + 1};
        case Direction::W:
            return Position{curr.x - 1, curr.y};
        case Direction::NW:
            return Position{curr.x - 1, curr.y - 1};
        default:
            return curr; // No movement if direction is invalid
    }
}

bool Floor::isComplete() const {
    return complete;
}

bool Floor::playerMove(Direction dir) {
    Position curr = player->getPos();
    Position next = target(curr, dir);
    if (grid[next.x][next.y]->isSpace()) {
        if (grid[next.x][next.y]->getEntityType() == EntityType::STAIR) {
            comlete = true; // Player has reached the stairs
        } else if (grid[next.x][next.y]->getEntityType() == EntityType::TREASURE) {
            auto treasure = dynamic_cast<Treasure*>(grid[next.x][next.y]);
            player->useItem(treasure);
            grid[next.x][next.y] = nullptr;
        }
        player->move(dir);
        std::swap(grid[curr.x][curr.y], grid[next.x][next.y]);
        notifyObservers(); // Notify observers of the player's move
        return true;
    }
    return false;
    // isFloor() for enemy
}

bool Floor::playerAttack(Direction dir) {
    Position curr = player->getPos();
    Position next = target(curr, dir);
    if (grid[next.x][next.y]->getEntityType() == EntityType::ENEMY) {
        auto enemy = dynamic_cast<Enemy*>(grid[next.x][next.y]);
        player->attack(grid[next.x][next.y]);
        if (enemy->isDead()) {
            handleEnemyDeath(enemy);
            notifyObservers(); // Notify observers of the enemy's death
            return true;
        }
    }
    return false;
}

bool Floor::playerUseItem(Direction dir) {
    Position curr = player->getPos();
    Position next = target(curr, dir);
    if (grid[next.x][next.y]->getEntityType() == EntityType::POTION) {
        auto potion = dynamic_cast<Potion*>(grid[next.x][next.y]);
        player->useItem(potion);
        // Remove the item from the grid
        grid[next.x][next.y] = nullptr;
        notifyObservers(); // Notify observers of the item usage
        return true;
    }
    return false;
}

void Floor::enemyTurn() {
    for ((int x = 0; x < grid) {
        for (auto entity : row) {
            if (entity && entity->getEntityType() == EntityType::ENEMY) {
                auto enemy = dynamic_cast<Enemy*>(entity);
                if (enemy) {
                    enemy->update(); // Call the update method of the enemy
                    notifyObservers(); // Notify observers after each enemy's turn
                }
            }
        }
    })
}

void Floor::handleEnemyDeath(Enemy* enemy) {
    // Handle the death of an enemy
    Position pos = enemy->getPos();
    grid[pos.x][pos.y] = nullptr; // Remove the enemy from the grid
    auto it = std::find_if(enemies.begin(), enemies.end(), 
                           [enemy](const std::unique_ptr<Enemy>& e) { return e.get() == enemy; });
    if (it != enemies.end()) {
        enemies.erase(it); // Remove the enemy from the list
    }
    notifyObservers(); // Notify observers of the enemy's death
}


// enemy具体的attack和move的逻辑（比如merchant非hostile时不攻击，dragon不移动）由method override来实现，
// floor只要满足条件就call attack和move。
//////////////////////////////////////////////////////////////
// Some previously-implemented enemy methods to make reference to:


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
