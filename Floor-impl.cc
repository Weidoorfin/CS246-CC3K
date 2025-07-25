module floor;

import <iostream>;
import <fstream>;
import <memory>;
import <string>;
import <vector>;
import <sstream>;
import <algorithm>;
import <cmath>;

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
import concreteenemies;
import potionfactory;
import tile;
import tilefactory;


Floor::Floor(){
    // Initialize the grid with empty chambers
    std::ifstream emptyMap{"emptyfloor.txt"};
    getEmptyMap(emptyMap);
    identifyChambers();
    GeneratePlayerpos();
    GenerateStairs();
    GenerateEntities();
     // Notify observers that the floor has been initialized
}

Floor::Floor(std::istringstream &is) {
    readFromStream(is);
     // Notify observers that the floor has been initialized
}

void Floor::setPlayer(Player* p) {
    player = p;
    player->setPos(playerpos);
    grid[playerpos.y][playerpos.x] = player; // Place player in the grid
}

bool Floor::isComplete() const {
    return complete;
}

const std::vector<std::vector<Entity*>>& Floor::getGrid() const {
    return grid;
}

const std::vector<std::vector<Entity*>>& Floor::getTerrain() const {
    return terrain;
}

Player* Floor::getPlayer() const {
    return player;
}

Entity* Floor::getItemAt(Position pos) const {
    return grid[pos.y][pos.x];
}

std::pair<bool, Entity*> Floor::playerMove(Direction dir) {
    Position curr = player->getPos();
    Position next = target(curr, dir);

    Entity* nextEntity = grid[next.y][next.x];
    Tile* nextTile = dynamic_cast<Tile*>(terrain[next.y][next.x]);

    // makes sure next tile and entity are both space
    if (nextEntity && !(nextEntity->isSpace() && nextTile->isSpace()))
        return {false, nullptr};

    
    if (nextTile && nextTile->getTileType() == TileType::Stair) {
        complete = true;
    }

    Entity* itemToReturn = nullptr;
    if (nextEntity && (nextEntity->getEntityType() == EntityType::TREASURE || 
                      nextEntity->getEntityType() == EntityType::POTION)) {
        itemToReturn = nextEntity;
        grid[next.y][next.x] = nullptr;
    }

    player->move(dir);
    grid[next.y][next.x] = player;
    grid[curr.y][curr.x] = nullptr;

    return {true, itemToReturn};
}

bool Floor::playerAttack(Direction dir) {
    Position curr = player->getPos();
    Position next = target(curr, dir);
    if (grid[next.y][next.x] && grid[next.y][next.x]->getEntityType() == EntityType::ENEMY) {
        auto enemy = dynamic_cast<Enemy*>(grid[next.y][next.x]);
        player->attack(*enemy);  // Dereference the pointer to pass as reference
        if (!enemy->isAlive()) {
            handleEnemyDeath(enemy);
        }
        return true;
    }
    return false;
}

std::pair<bool, Entity*> Floor::playerUseItem(Direction dir) {
    Position curr = player->getPos();
    Position next = target(curr, dir);
    if (grid[next.y][next.x] && grid[next.y][next.x]->getEntityType() == EntityType::POTION) {
        Entity* potion = grid[next.y][next.x];
        grid[next.y][next.x] = nullptr;
        // Notify observers of the item usage
        return {true, potion};
    }
    return {false, nullptr};
}

// Perform enemy actions for the turn
void Floor::enemyTurn() {
    if (Enemy::isGlobalMovementDisabled()) {
        return;
    }
    
    for (size_t x = 0; x < grid[0].size(); ++x) {
        for (size_t y = 0; y < grid.size(); ++y) {
            Entity* entity = grid[y][x];
            if (entity && entity->getEntityType() == EntityType::ENEMY) {
                Enemy* enemy = dynamic_cast<Enemy*>(entity);
                
                if (enemy->getmoveToggle()) {
                    continue;
                }
                
                bool attacked = false;
                
                // Check if this enemy is a Dragon with special attack range
                auto dragon = dynamic_cast<Dragon*>(enemy);
                if (dragon && dragon->isGuarding()) {
                    // Dragon attacks if player is adjacent to Dragon OR adjacent to its hoard
                    Position hoardPos = dragon->getHoard()->getPos();
                    bool playerNearHoard = isAdjacent(player->getPos(), hoardPos);
                    bool playerNearDragon = isAdjacent(enemy->getPos(), player->getPos());
                    
                    if (playerNearDragon || playerNearHoard) {
                        enemy->attack(*player);
                        enemy->toggleMove();
                        attacked = true;
                    }
                } else {
                    // Normal enemy attack logic
                    if (isAdjacent(enemy->getPos(), player->getPos())) {
                        enemy->attack(*player);
                        enemy->toggleMove();
                        attacked = true;
                    }
                }
                
                if (!attacked) {
                    RandomEngine rng;
                    std::vector<Direction> directions = rng.genDirections();

                    for (auto &dir : directions) {
                        Position next = target(enemy->getPos(), dir);
                        if (next.y >= 0 && next.y < grid.size() && 
                            next.x >= 0 && next.x < grid[next.y].size()) {

                            if (grid[next.y][next.x] == nullptr && 
                                terrain[next.y][next.x]->isFloor()) {
                                
                                // Check if this enemy is a Dragon with movement restrictions
                                auto* dragon = dynamic_cast<Dragon*>(enemy);
                                if (dragon && dragon->isGuarding()) {
                                    // Check if Dragon can move to this position (within 1 tile of hoard)
                                    Position hoardPos = dragon->getHoard()->getPos();
                                    int deltaX = abs(next.x - hoardPos.x);
                                    int deltaY = abs(next.y - hoardPos.y);
                                    
                                    if (deltaX <= 1 && deltaY <= 1) {
                                        // Within range, can move
                                        enemy->move(dir);
                                        grid[next.y][next.x] = enemy;
                                        grid[y][x] = nullptr;
                                        enemy->toggleMove();
                                        break;
                                    }
                                    // If not within range, try next direction
                                } else {
                                    // Normal enemy movement
                                    enemy->move(dir);
                                    grid[next.y][next.x] = enemy;
                                    grid[y][x] = nullptr;
                                    enemy->toggleMove();
                                    break;
                                }
                            }
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

    if (enemy->getRace() == Race::MERCHANT) {
        TreasureFactory tf;
        treasures.push_back(tf.createTreasure(TreasureType::SMALL, pos));
        grid[pos.y][pos.x] = treasures.back().get();
    } else if (enemy->getRace() == Race::HUMAN) {
        TreasureFactory tf;
        treasures.push_back(tf.createTreasure(TreasureType::MERCHANT, pos));
        grid[pos.y][pos.x] = treasures.back().get();
    }
    auto it = std::find_if(enemies.begin(), enemies.end(),
        [enemy](const std::unique_ptr<Enemy>& e) { return e.get() == enemy; });
    if (it != enemies.end()) enemies.erase(it);

}

void Floor::getEmptyMap(std::ifstream &is) {
    // Implementation for reading an empty map from the input stream
    // This will populate the grid and tileTypes with initial values
    std::string line;
    TileFactory tf;
    int y = 0;
    while (getline(is, line)) {
        std::vector<Entity*> terrainRow;
        std::vector<Entity*> gridRow;
        int x = 0;
        for (char c : line) {
            Position pos{x, y};
            switch (c) {
                case '-':
                    tiles.push_back(tf.createTile(TileType::HorizontalWall, pos));
                    terrainRow.push_back(tiles.back().get());
                    gridRow.push_back(nullptr);
                    break;
                case '|': 
                    tiles.push_back(tf.createTile(TileType::VerticalWall, pos));
                    terrainRow.push_back(tiles.back().get());
                    gridRow.push_back(nullptr);
                    break;
                case '.':  
                    tiles.push_back(tf.createTile(TileType::Floor, pos));
                    terrainRow.push_back(tiles.back().get());
                    gridRow.push_back(nullptr);
                    break;
                case '+': 
                    tiles.push_back(tf.createTile(TileType::Door, pos));
                    terrainRow.push_back(tiles.back().get());
                    gridRow.push_back(nullptr);
                    break;
                case '#': 
                    tiles.push_back(tf.createTile(TileType::Corridor, pos));
                    terrainRow.push_back(tiles.back().get());
                    gridRow.push_back(nullptr);
                    break;
                case '/': 
                    tiles.push_back(tf.createTile(TileType::Stair, pos));
                    terrainRow.push_back(tiles.back().get());
                    gridRow.push_back(nullptr);
                    stairs = pos;
                    break;
                // Handle generated entities
                case ' ':
                    tiles.push_back(tf.createTile(TileType::Nothing, pos));
                    terrainRow.push_back(tiles.back().get());
                    gridRow.push_back(nullptr);
                    break;
            }
            x++;
        } // for (char c : line)
        terrain.push_back(terrainRow);
        grid.push_back(gridRow);
        y++;
    }
}

void Floor::identifyChambers() {
    int height = static_cast<int>(terrain.size());
    int width = static_cast<int>(terrain[0].size());
    std::vector<std::vector<bool>> visited(height, std::vector<bool>(width, false));

    for (int y = 0; y < height; ++y) {
        for (int x = 0; x < width; ++x) {
            auto tile = dynamic_cast<Tile*>(terrain[y][x]);
            if (tile && !visited[y][x] && tile->getTileType() == TileType::Floor) {
                auto chamber = std::make_unique<Chamber>();
                dfsFillChamber(x, y, chamber.get(), visited);
                chambers.push_back(std::move(chamber));
            }
        }
    }
}

void Floor::dfsFillChamber(int x, int y, Chamber* chamber, std::vector<std::vector<bool>>& visited) {

    if (visited[y][x]) return;
    
    auto tile = dynamic_cast<Tile*>(terrain[y][x]);

    if (x < 0 || x >= terrain[0].size() || y < 0 || y >= terrain.size() || 
        !tile || tile->getTileType() != TileType::Floor) {
        return;
    }
    visited[y][x] = true;
    chamber->addTile(Position{x, y});

    int dx[] = {1, -1, 0, 0};
    int dy[] = {0, 0, 1, -1};
    for (size_t d = 0; d < 4; ++d) {
        dfsFillChamber(x + dx[d], y + dy[d], chamber, visited);
    }
}

void Floor::GeneratePlayerpos() {
    // Implementation for generating the player on the floor
    RandomEngine re;
    size_t r = re.genIndices(0, chambers.size() - 1)[0];
    Position playerPos = chambers[r]->getRandomTile();
    chambers[r]->setWithPlayer(); // Mark the chamber as occupied by player
    playerpos = playerPos; // Store the player's position
}

void Floor::GenerateStairs() {
    RandomEngine re;
    TileFactory tilef;
    std::vector<int> indices = re.genIndices(0, chambers.size() - 1);
    size_t r = 0;
    while (r < indices.size() && !chambers[indices[r]]->isWithPlayer()) {
        r++;
    }
    stairs = chambers[r]->getRandomTile();
    tiles.push_back(tilef.createTile(TileType::Stair, stairs));
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
            auto* dragonHoard = dynamic_cast<DragonHoard*>(treasures.back().get());
            
            for (auto &dir : re.genDirections()) {
                Position next = target(pos, dir);
                if (terrain[next.y][next.x] && terrain[next.y][next.x]->isSpace()) {
                    enemies.push_back(ef.createEnemy(Race::DRAGON, next));
                    auto* dragon = dynamic_cast<Dragon*>(enemies.back().get());
                    
                    // 只设置 Dragon 的 hoard 指针
                    if (dragon && dragonHoard) {
                        dragon->setHoard(dragonHoard);
                    }
                    
                    grid[next.y][next.x] = enemies.back().get();
                    break;
                }
            }
        }
    } // generate treasures
}

void Floor::readFromStream(std::istringstream &is) {
    std::string line;
    int y = 0;
    while (getline(is, line)) {
        int x = 0;
        std::vector<Entity*> terrainRow;
        std::vector<Entity*> gridRow; // Store entities in the grid
        EnemyFactory ef;
        PotionFactory pf;
        TreasureFactory tf;
        TileFactory tilef;
        for (char c : line) {
            Position pos{x, y};
            switch (c) {
                case '-':
                    tiles.push_back(tilef.createTile(TileType::HorizontalWall, pos));
                    terrainRow.push_back(tiles.back().get());
                    gridRow.push_back(nullptr);
                    break;
                case '|': 
                    tiles.push_back(tilef.createTile(TileType::VerticalWall, pos));
                    terrainRow.push_back(tiles.back().get());
                    gridRow.push_back(nullptr);
                    break;
                case '.':  
                    tiles.push_back(tilef.createTile(TileType::Floor, pos));
                    terrainRow.push_back(tiles.back().get());
                    gridRow.push_back(nullptr);
                    break;
                case '+': 
                    tiles.push_back(tilef.createTile(TileType::Door, pos));
                    terrainRow.push_back(tiles.back().get());
                    gridRow.push_back(nullptr);
                    break;
                case '#': 
                    tiles.push_back(tilef.createTile(TileType::Corridor, pos));
                    terrainRow.push_back(tiles.back().get());
                    gridRow.push_back(nullptr);
                    break;
                case '\\': 
                    tiles.push_back(tilef.createTile(TileType::Stair, pos));
                    terrainRow.push_back(tiles.back().get());
                    gridRow.push_back(nullptr);
                    stairs = pos;
                    break;
                // Handle generated entities
                case ' ':
                    tiles.push_back(tilef.createTile(TileType::Nothing, pos));
                    terrainRow.push_back(tiles.back().get());
                    gridRow.push_back(nullptr); 
                    break;
                case '@': 
                    // Create player entity
                    tiles.push_back(tilef.createTile(TileType::Floor, pos));
                    terrainRow.push_back(tiles.back().get());
                    gridRow.push_back(nullptr);
                    playerpos = pos; // Set player position
                    break;
                case 'H':
                    tiles.push_back(tilef.createTile(TileType::Floor, pos));
                    terrainRow.push_back(tiles.back().get());
                    enemies.push_back(ef.createEnemy(Race::HUMAN, pos));
                    gridRow.push_back(enemies.back().get());
                    break;
                case 'W':
                    tiles.push_back(tilef.createTile(TileType::Floor, pos));
                    terrainRow.push_back(tiles.back().get());
                    enemies.push_back(ef.createEnemy(Race::DWARF, pos));
                    gridRow.push_back(enemies.back().get());
                    break;
                case 'E':
                    tiles.push_back(tilef.createTile(TileType::Floor, pos));
                    terrainRow.push_back(tiles.back().get());
                    enemies.push_back(ef.createEnemy(Race::ELF, pos));
                    gridRow.push_back(enemies.back().get());
                    break;
                case 'O':
                    tiles.push_back(tilef.createTile(TileType::Floor, pos));
                    terrainRow.push_back(tiles.back().get());
                    enemies.push_back(ef.createEnemy(Race::ORC, pos));
                    gridRow.push_back(enemies.back().get());
                    break;
                case 'M':
                    tiles.push_back(tilef.createTile(TileType::Floor, pos));
                    terrainRow.push_back(tiles.back().get());
                    enemies.push_back(ef.createEnemy(Race::MERCHANT, pos));
                    gridRow.push_back(enemies.back().get());
                    break;
                case 'D':
                    tiles.push_back(tilef.createTile(TileType::Floor, pos));
                    terrainRow.push_back(tiles.back().get());
                    enemies.push_back(ef.createEnemy(Race::DRAGON, pos));
                    gridRow.push_back(enemies.back().get());
                    break;
                case 'L':
                    tiles.push_back(tilef.createTile(TileType::Floor, pos));
                    terrainRow.push_back(tiles.back().get());
                    enemies.push_back(ef.createEnemy(Race::HALFLING, pos));
                    gridRow.push_back(enemies.back().get());
                    break;
                case '0':
                    tiles.push_back(tilef.createTile(TileType::Floor, pos));
                    terrainRow.push_back(tiles.back().get());
                    potions.push_back(pf.createPotion(PotionType::RH, pos));
                    gridRow.push_back(potions.back().get());
                    break;
                case '1':
                    tiles.push_back(tilef.createTile(TileType::Floor, pos));
                    terrainRow.push_back(tiles.back().get());
                    potions.push_back(pf.createPotion(PotionType::BA, pos));
                    gridRow.push_back(potions.back().get());
                    break;
                case '2':
                    tiles.push_back(tilef.createTile(TileType::Floor, pos));
                    terrainRow.push_back(tiles.back().get());
                    potions.push_back(pf.createPotion(PotionType::BD, pos));
                    gridRow.push_back(potions.back().get());
                    break;
                case '3':
                    tiles.push_back(tilef.createTile(TileType::Floor, pos));
                    terrainRow.push_back(tiles.back().get());
                    potions.push_back(pf.createPotion(PotionType::PH, pos));
                    gridRow.push_back(potions.back().get());
                    break;
                case '4':
                    tiles.push_back(tilef.createTile(TileType::Floor, pos));
                    terrainRow.push_back(tiles.back().get());
                    potions.push_back(pf.createPotion(PotionType::WA, pos));
                    gridRow.push_back(potions.back().get());
                    break;
                case '5':
                    tiles.push_back(tilef.createTile(TileType::Floor, pos));
                    terrainRow.push_back(tiles.back().get());
                    potions.push_back(pf.createPotion(PotionType::WD, pos));
                    gridRow.push_back(potions.back().get());
                    break;
                case '6': // small
                    tiles.push_back(tilef.createTile(TileType::Floor, pos));
                    terrainRow.push_back(tiles.back().get());
                    treasures.push_back(tf.createTreasure(TreasureType::SMALL, pos));
                    gridRow.push_back(treasures.back().get());
                    break;
                case '7': // medium
                    tiles.push_back(tilef.createTile(TileType::Floor, pos));
                    terrainRow.push_back(tiles.back().get());
                    treasures.push_back(tf.createTreasure(TreasureType::NORMAL, pos));
                    gridRow.push_back(treasures.back().get());
                    break;
                case '8': // merchant
                    tiles.push_back(tilef.createTile(TileType::Floor, pos));
                    terrainRow.push_back(tiles.back().get());
                    treasures.push_back(tf.createTreasure(TreasureType::MERCHANT, pos));
                    gridRow.push_back(treasures.back().get());
                    break;
                case '9': // dragon
                    tiles.push_back(tilef.createTile(TileType::Floor, pos));
                    terrainRow.push_back(tiles.back().get());
                    treasures.push_back(tf.createTreasure(TreasureType::DRAGON, pos));
                    gridRow.push_back(treasures.back().get());
                    break;
                
            }
            x++;
        } // for (char c : line)
        terrain.push_back(terrainRow);
        grid.push_back(gridRow);
        y++;
    } // while (getline(is, line))
    
    bindDragonsToHoards();
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

void Floor::toggleAllEnemyMovement() {
    Enemy::toggleGlobalMovement();
}

void Floor::resetAllEnemyMoveToggle() {
    for (auto& enemy : enemies) {
        if (enemy) {
            enemy->resetMoveToggle();
        }
    }
}

bool Floor::isHoardGuarded(DragonHoard* hoard) const {
    if (!hoard) return false;
    
    Position hoardPos = hoard->getPos();
    
    // 检查附近8个方向是否有活着的Dragon守护这个hoard
    for (int dx = -1; dx <= 1; ++dx) {
        for (int dy = -1; dy <= 1; ++dy) {
            if (dx == 0 && dy == 0) continue; // 跳过宝藏自身位置
            
            Position searchPos{hoardPos.x + dx, hoardPos.y + dy};
            // 检查边界
            if (searchPos.x >= 0 && searchPos.y >= 0 && 
                searchPos.y < grid.size() && searchPos.x < grid[searchPos.y].size()) {
                
                Entity* entity = grid[searchPos.y][searchPos.x];
                if (entity && entity->getEntityType() == EntityType::ENEMY) {
                    auto* dragon = dynamic_cast<Dragon*>(entity);
                    if (dragon && dragon->isAlive() && dragon->isGuarding() && 
                        dragon->getHoard() == hoard) {
                        return true; // 找到活着的守护龙
                    }
                }
            }
        }
    }
    
    return false; // 没有找到守护龙
}

Position Floor::target(Position curr, Direction dir) {
    switch(dir) {
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
            return curr;
    }
}

bool Floor::isAdjacent(Position a, Position b) {
    return (abs(a.x - b.x) <= 1 && abs(a.y - b.y) <= 1 && !(a.x == b.x && a.y == b.y));
}

void Floor::bindDragonsToHoards() {
    // 遍历所有 DragonHoard，为每个寻找附近的 Dragon
    for (auto& treasure : treasures) {
        if (treasure->getTreasureType() == TreasureType::DRAGON) {
            auto* dragonHoard = dynamic_cast<DragonHoard*>(treasure.get());
            if (!dragonHoard) continue;
            
            Position hoardPos = dragonHoard->getPos();
            Dragon* nearbyDragon = nullptr;
            
            // 搜索附近8个方向的 Dragon
            for (int dx = -1; dx <= 1; ++dx) {
                for (int dy = -1; dy <= 1; ++dy) {
                    if (dx == 0 && dy == 0) continue; // 跳过当前位置
                    
                    Position searchPos{hoardPos.x + dx, hoardPos.y + dy};
                    // 检查边界
                    if (searchPos.x >= 0 && searchPos.y >= 0 && 
                        searchPos.y < grid.size() && searchPos.x < grid[searchPos.y].size()) {
                        
                        Entity* entity = grid[searchPos.y][searchPos.x];
                        if (entity && entity->getEntityType() == EntityType::ENEMY) {
                            auto* dragon = dynamic_cast<Dragon*>(entity);
                            if (dragon && !dragon->isGuarding()) {
                                nearbyDragon = dragon;
                                break;
                            }
                        }
                    }
                }
                if (nearbyDragon) break;
            }
            
            // 只设置 Dragon 的 hoard 指针，不设置 DragonHoard 的 guardian
            if (nearbyDragon) {
                nearbyDragon->setHoard(dragonHoard);
            }
        }
    }
}
