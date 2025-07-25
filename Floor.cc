export module floor;

import <iostream>;
import <fstream>;
import <sstream>;
import <memory>;
import <string>;
import <vector>;
import <algorithm>;
import <utility>;

import enums;
import position;
import randomengine;
import abstractos;
import player;
import enemy;
import enemyfactory;
import item;
import entity;
import tile;
import potion;
import treasure;
import treasurefactory;
import potionfactory;

import chamber;


export class Floor {
    Position stairs; // Position of the stairs
    bool complete = false;

    std::vector<std::vector<Entity*>> terrain; // Types of tiles of terrain
    std::vector<std::vector<Entity*>> grid; // record pointer, with movable entities
    
    std::vector<std::unique_ptr<Enemy>> enemies; // List of enemies on the floor
    std::vector<std::unique_ptr<Potion>> potions; 
    std::vector<std::unique_ptr<Treasure>> treasures;
    std::vector<std::unique_ptr<Tile>> tiles;
    std::vector<std::unique_ptr<Chamber>> chambers; // Chambers in the floor
    Position playerpos; // Position of the player
    Player *player; // Player on the floor


 public:

    // Constructors
    Floor(bool DLC);
    // Constructor with infile
    explicit Floor(std::istringstream &is); // Constructor to read from input stream

    // Accessories and mutators

    // Initualize the player to the floor, also set player position to designated Playerpos
    // generated when random generation
    void setPlayer(Player* p);

    // Used especially for the decorator, Potion, so that the player is pointing to the new
    // decorated player
    void renewPlayer(Player* p);
    // Checks if the player reaches the stairs
    bool isComplete() const;
    // Get the grid of the floor, especially use for TextDisplay module
    const std::vector<std::vector<Entity*>>& getGrid() const;
    // Get the terrain of the floor, especially use for TextDisplay module
    const std::vector<std::vector<Entity*>>& getTerrain() const;
    // Get the player on the floor, especially use for TextDisplay module
    Player* getPlayer() const;
    // Get specific item at given position, use for Game module
    Entity* getItemAt(Position pos) const; // Get the item at a specific position

    // Player actions

    // Move the player with the given direction, also detects if the position is valid 
    // and if the position contains any pickable item
    // If move is available, return first bool is true, and second is the Entity pointer at position
    // If move is not available, return first bool is false, and second is nullptr
    std::pair<bool, Entity*> playerMove(Direction dir);

    // Player attack with the given direction, return true if attack is available
    bool playerAttack(Direction dir);

    // Player pick up item at the given position
    // return first bool is true if given diretion contains an item, and second as Entity pointer
    // If no item at the position, return first bool is false, and second is nullptr

    std::pair<bool, Entity*> playerUseItem(Direction dir);

    // Handle enemy turn, first detects if the player is adjacent to any enemy, and then
    // handle the enemy's action based on the enemy type
    // If the player is adjacent to an enemy, enemy will attack the player
    // If the player is not adjacent to any enemy, enemies will randomly move
    void enemyTurn();

    // Handle enemy death, remove the enemy from the floor and update the grid, if they have
    // ability to drop items or other stuff
    void handleEnemyDeath(Enemy* enemy);

    // toggle the switch of all enemies' movement, globally
    void toggleAllEnemyMovement();

    // Reset the move toggle of all enemies, used for single turn
    void resetAllEnemyMoveToggle();

    // Check if a DragonHoard is guarded
    bool isHoardGuarded(DragonHoard* hoard) const;


  private:

    // Read an empty map from input stream
    void getEmptyMap(std::ifstream &is);

    // Identify chambers in the floor, start algorithm when Floor is detected
    void identifyChambers();

    // Fill the chamber with Deep First Search (DFS) algorithm
    // expanding towards 4 directions and fill until edge is reached
    // visited is used to track if position is already visited
    void dfsFillChamber(int x, int y, Chamber* chamber, std::vector<std::vector<bool>>& visited);

    // Generate the floor with random generation
    // store it at Playerpos
    void GeneratePlayerpos();

    // Generate the stairs position, which is the exit of the floor
    // The stairs will not be placed in the same chamber as the player
    void GenerateStairs();

    // Generate all entities on the floor with given probabilities
    void GenerateEntities();

    // Get map from input stream, also read all entities and allocate them on grid
    void readFromStream(std::istringstream &is);

    // Binding dragons to their hoards in the floor, only used when reading generated floor
    void bindDragonsToHoards();

    // Translates a direction to a position change
    Position target(Position curr, Direction dir);

    // checks if two positions are adjacent by comparing their coordinates
    bool isAdjacent(Position a, Position b);

    // detect DLC
    std::string detectDLC(FloorName floorName) const;
};
