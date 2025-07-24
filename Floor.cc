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
    Player *player; // Player on the floor ?

 public:
    Floor(); // Default constructor
    explicit Floor(std::istream &is); // Constructor to read from input stream

    // Accessories and mutators
    void setPlayer(Player* p); // Set the player on the floor
    bool isComplete() const; // Check if the floor is complete
    const std::vector<std::vector<Entity*>>& getGrid() const; // Get the grid of entities
    const std::vector<std::vector<Entity*>>& getTerrain() const; // Get the terrain of the floor
    Player* getPlayer() const; // Get the player on the floor

    // Player actions
    std::pair<bool, Entity*> playerMove(Direction dir); // Move the player in a direction, return success and item
    bool playerAttack(Direction dir); // Attack a character
    std::pair<bool, Entity*> playerUseItem(Direction dir); // Use an item, return success and item
    void enemyTurn(); // Perform enemy actions for the turn
    void handleEnemyDeath(Enemy* enemy); // Handle the death of an enemy
    void toggleAllEnemyMovement(); // Toggle movement for all enemies on the floor
    void resetAllEnemyMoveToggle(); // Reset all enemies' move toggle for new turn

  private:
    void getEmptyMap(std::ifstream &is); // Read an empty map from input stream
    void identifyChambers(); // Identify chambers in the floor
    void dfsFillChamber(int x, int y, Chamber* chamber, std::vector<std::vector<bool>>& visited); // Depth-first search to fill a chamber
    void GeneratePlayerpos(); // Generate the player position on the floor
    void GenerateStairs(); // Generate stairs on the floor
    void GenerateEntities(); // Generate entities (enemies, items) on the floor
    void readFromStream(std::istream &is); // Read floor data from input stream
    Position target(Position curr, Direction dir); // Get the target position based on current position and direction
    bool isAdjacent(Position a, Position b); // Check if two positions are adjacent

};
