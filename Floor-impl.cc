module floor;

import <iostream>;
import <fstream>;
import <memory>;
import <string>;
import <vector>;
import <sstream>;
import <algorithm>;

import enums;
import chamber;
import enemy;
import item;
import potion;
import treasure;
import position;
import abstractos;
import entity;
import player;
import enemyfactory;
import randomengine;
import treasurefactory;
import potionfactory;


Floor::Floor(){
    // Initialize the grid with empty chambers
    ifstream emptyMap("emptyfloor.txt");
    getEmptyMap(emptyMap);
    identifyChambers();
    GeneratePlayerpos();
    GenerateStairs();
    GenerateEntities();
     // Notify observers that the floor has been initialized
}

Floor::Floor(std::istream &is) {
    readFromStream(is);
     // Notify observers that the floor has been initialized
}

Floor::Floor(std::istream &is, int seed) {
    readFromStream(is);
    // Set the random seed for the floor
     // Notify observers that the floor has been initialized
}

void Floor::setPlayer(std::unique_ptr<Player> p) {
    player = std::move(p);
    player->setPosition(playerpos);
}

bool Floor::isComplete() const {
    return complete;
}

const std::vector<std::vector<Entity*>>& Floor::getGrid() const {
    return grid;
}

const std::vector<std::vector<Tile*>>& Floor::getTerrain() const {
    return terrain;
}

bool Floor::playerMove(Direction dir) {
    Position curr = player->getPos();
    Position next = target(curr, dir);
    if (grid[next.y][next.x]->isSpace()) {
        if (grid[next.y][next.x]->getEntityType() == EntityType::STAIR) {
            complete = true; // Player has reached the stairs
        } else if (grid[next.y][next.x]->getEntityType() == EntityType::TREASURE) {
            auto treasure = dynamic_cast<Treasure*>(grid[next.y][next.x]);
            player = treasure.applyEffect(std::make_unique<Player>(*player));
            grid[next.y][next.x] = nullptr;
        }
        player->move(dir);
        std::swap(grid[curr.y][curr.x], grid[next.y][next.x]);
         // Notify observers of the player's move
        return true;
    }
    return false;
    // isFloor() for enemy
}

bool Floor::playerAttack(Direction dir) {
    Position curr = player->getPos();
    Position next = target(curr, dir);
    if (grid[next.y][next.x]->getEntityType() == EntityType::ENEMY) {
        auto enemy = dynamic_cast<Enemy*>(grid[next.y][next.x]);
        player->attack(grid[next.y][next.x]);
        if (enemy->isDead()) {
            handleEnemyDeath(enemy);
             // Notify observers of the enemy's death
            return true;
        }
    }
    return false;
}

bool Floor::playerUseItem(Direction dir) {
    Position curr = player->getPos();
    Position next = target(curr, dir);
    if (grid[next.y][next.x]->getEntityType() == EntityType::POTION) {
        auto potion = dynamic_cast<Potion*>(grid[next.y][next.x]);
        player = potion->applyEffect(std::make_unique<Player>(*player));
        // Remove the item from the grid
        grid[next.y][next.x] = nullptr;
         // Notify observers of the item usage
        return true;
    }
    return false;
}

// Perform enemy actions for the turn
void Floor::enemyTurn() {
    for (auto enemy : enemies) {
        enemy->moveToggle();
    }
    for (int y = 0; y < grid[0].size(); ++y) {
        for (int x = 0; x < grid.size(); ++x) {
            Entity* entity = grid[x][y];
            if (entity && entity->getEntityType() == EntityType::ENEMY) {
                Enemy* enemy = dynamic_cast<Enemy*>(entity);
                bool attacked = false;
                if (enemy->getMoveToggle()) {
                    for (int dx = -1; dx <= 1 && !attacked; ++dx) {
                        for (int dy = -1; dy <= 1 && !attacked; ++dy) {
                            if (dx == 0 && dy == 0) continue;
                            int nx = x + dx, ny = y + dy;
                            if(adjacent(enemy->getPos(), player->getPos()) && 
                               grid[ny][nx] && 
                               grid[ny][nx]->getEntityType() == EntityType::PLAYER) {
                                enemy->attack(*player);
                                enemy->moveToggle();
                                attacked = true;
                                 // Notify observers of the attack
                            }
                        }
                    }
                    if (attacked) continue;
                    RandomEngine rng;
                    vector<Direction> directions = rng.genDirections();

                    for (auto &dir : directions) {
                        Position next = target(enemy->getPos(), dir);
                        if (grid[next.y][next.x]->isSpace()) {
                            enemy->move(dir);
                            std::swap(grid[enemy->getPos().y][enemy->getPos().x], grid[next.y][next.x]);
                            
                            break;
                        }
                    }
                }
            }
        }
    }
}



void Floor::handleEnemyDeath(Enemy* enemy) {
    Position pos = enemy->getPos();
    grid[pos.y][pos.x] = nullptr;

    if (auto merchant = dynamic_cast<Merchant*>(enemy)) {
        treasures.push_back(tf.createTreasure(TreasureType::SMALL, pos));
        grid[pos.y][pos.x] = treasures.back().get();
    } else if (auto human = dynamic_cast<Human*>(enemy)) {
        treasures.push_back(tf.createTreasure(TreasureType::MERCHANT, pos));
        grid[pos.y][pos.x] = treasures.back().get();
    }
    auto it = std::find_if(enemies.begin(), enemies.end(),
        [enemy](const std::unique_ptr<Enemy>& e) { return e.get() == enemy; });
    if (it != enemies.end()) enemies.erase(it);

    
}

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

void Floor::identifyChambers() {
    int height = tileTypes.size();
    int width = tileTypes[0].size();
    std::vector<std::vector<bool>> visited(height, std::vector<bool>(width, false));

    for (int y = 0; y < height; ++y) {
        for (int x = 0; x < width; ++x) {
            if (!visited[y][x] && tileTypes[y][x] == TileType::Floor) {
                auto chamber = std::make_unique<Chamber>();
                dfsFillChamber(x, y, chamber.get(), visited);
                chambers.push_back(std::move(chamber));
            }
        }
    }
}

void Floor::dfsFillChamber(int x, int y, Chamber* chamber, std::vector<std::vector<bool>>& visited) {

    if (!visited[y][x] || tileTypes[y][x] != TileType::Floor) return;

    visited[y][x] = true;
    chamber->addTile(Position{x, y});

    int dx[] = {1, -1, 0, 0};
    int dy[] = {0, 0, 1, -1};
    for (int d = 0; d < 4; ++d) {
        dfsFillChamber(x + dx[d], y + dy[d], chamber, visited);
    }
}

void Floor::GeneratePlayerpos() {
    // Implementation for generating the player on the floor
    RandomEngine re;
    int r = re.genIndices(0, chambers.size() - 1)[0];
    Position playerPos = chambers[r]->getRandomTile();
    chambers[r]->setWithPlayer(); // Mark the chamber as occupied by player
    player->setPosition(playerPos);
}

void Floor::GenerateStairs() {
    RandomEngine re;
    vector<int> indices = re.genIndices(0, chambers.size() - 1);
    int r = 0;
    while (r < indices.size() && !chambers[indices[r]]->isWithPlayer()) {
        r++;
    }
    stairs = chambers[r]->getRandomTile();
    tiles.push_back(std::make_unique<Tile>(TileType::Stair, stairs));
    terrain[stairs.y][stairs.x] = tiles.back().get(); // Set the stair tile in terrain
    grid[stairs.y][stairs.x] = nullptr; // Stairs are not occupied by any entity
    chambers[r]->addTile(stairs); // Add stairs
}

// not concrete, just a placeholder
void Floor::GenerateEntities() {
    // Implementation for generating entities (enemies, items) on the floor
    EnemyFactory ef;
    PotionFactory pf;
    TreasureFactory tf;
    RandomEngine re;
    for (int i = 0; i < 20; i++) {
        int r = re.genIndices(0, chambers.size() - 1)[0];
        Position pos = chambers[r]->getRandomTile();
        enemies.push_back(ef.createEnemy(re.genEnemyRace(), pos));
        grid[pos.y][pos.x] = enemies.back().get();
    } // generate enemies

    // Generate potions
    for (int i = 0; i < 10; i++) {
        int r = re.genIndices(0, chambers.size() - 1)[0];
        Position pos = chambers[r]->getRandomTile();
        potions.push_back(pf.createPotion(re.genPotionType(), pos));
        grid[pos.y][pos.x] = potions.back().get();
    } // generate potions

    // Generate treasures
    for (int i = 0; i < 10; i++) {
        int r = re.genIndices(0, chambers.size() - 1)[0];
        Position pos = chambers[r]->getRandomTile();
        treasures.push_back(tf.createTreasure(re.genTreasureType(), pos));
        grid[pos.y][pos.x] = treasures.back().get();
        if (treasures.back()->getTreasureType() == TreasureType::DRAGON) {
            for (auto &dir : re.genDirections()) {
                Position next = target(pos, dir);
                if (grid[next.y][next.x]->isSpace()) {
                    enemies.push_back(ef.createEnemy(Race::DRAGON, next));
                    grid[next.y][next.x] = enemies.back().get();
                    break;
                }
            }
        }
    } // generate treasures
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
                    enemies.push_back(ef.createEnemy(Race::Human, pos));
                    gridRow.push_back(enemies.back().get());
                    break;
                case 'W':
                    tiles.push_back(std::make_unique<Tile>(TileType::Floor, pos));
                    terrainRow.push_back(tiles.back().get());
                    enemies.push_back(ef.createEnemy(Race::DWARF, pos));
                    gridRow.push_back(enemies.back().get());
                    break;
                case 'E':
                    tiles.push_back(std::make_unique<Tile>(TileType::Floor, pos));
                    terrainRow.push_back(tiles.back().get());
                    enemies.push_back(ef.createEnemy(Race::ELF, pos));
                    gridRow.push_back(enemies.back().get());
                    break;
                case 'O':
                    tiles.push_back(std::make_unique<Tile>(TileType::Floor, pos));
                    terrainRow.push_back(tiles.back().get());
                    enemies.push_back(ef.createEnemy(Race::ORCS, pos));
                    gridRow.push_back(enemies.back().get());
                    break;
                case 'M':
                    tiles.push_back(std::make_unique<Tile>(TileType::Floor, pos));
                    terrainRow.push_back(tiles.back().get());
                    enemies.push_back(ef.createEnemy(Race::MERCHANT, pos));
                    gridRow.push_back(enemies.back().get());
                    break;
                case 'D':
                    tiles.push_back(std::make_unique<Tile>(TileType::Floor, pos));
                    terrainRow.push_back(tiles.back().get());
                    enemies.push_back(ef.createEnemy(Race::DRAGON, pos));
                    gridRow.push_back(enemies.back().get());
                    break;
                case 'L':
                    tiles.push_back(std::make_unique<Tile>(TileType::Floor, pos));
                    terrainRow.push_back(tiles.back().get());
                    enemies.push_back(ef.createEnemy(Race::HALFLING, pos));
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

bool isAdjacent(Position a, Position b) {
    return (abs(a.x - b.x) <= 1 && abs(a.y - b.y) <= 1);
}
