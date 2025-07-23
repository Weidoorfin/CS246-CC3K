export module floor;

import <vector>;

import chamber;
import enemy;
import item;
import tile;
import position;
import abstractos;

export class Floor : public Subject {
    Position stairs; // Position of the stairs
    bool complete = false;

    vector<vector<Entity*>> terrian; // Types of tiles of terrain
    vector<vector<Entity*>> grid; // record pointer, with movable entities
    
    vector<std::unique_ptr<Enemy>> enemies; // List of enemies on the floor
    vector<std::unique_ptr<Potion>> potions; 
    vector<std::unique_ptr<Treasure>> treasures;
    vector<std::unique_ptr<Tile>> tiles;
    vector<std::unique_ptr<Chamber>> chambers; // Chambers in the floor
    Position playerpos; // Position of the player
    Player *player; // Player on the floor ? // share_pointer?

 public:
    explicit Floor(); // Default constructor
    explicit Floor(std::istream &is); // Constructor to read from input stream
    explicit Floor(std::istream &is, int seed); // Constructor to read from input stream with seed

    // Accessories and mutators
    void setPlayer(std::unique_ptr<Player> p); // Set the player on the floor
    bool isComplete() const; // Check if the floor is complete

    // Player actions
    bool playerMove(Direction dir); // Move the player in a direction
    bool playerAttack(Direction dir); // Attack a character
    bool playerUseItem(Direction dir); // Use an item
    void enemyTurn(); // Perform enemy actions for the turn
    void handleEnemyDeath(Enemy* enemy); // Handle the death of an enemy

  private:
    void getEmptyMap(std::istream &is); // Read an empty map from input stream
    void identifyChambers(); // Identify chambers in the floor
    void dfsFillChamber(int x, int y, Chamber* chamber, std::vector<std::vector<bool>>& visited); // Depth-first search to fill a chamber
    void GeneratePlayerpos(); // Generate the player position on the floor
    void GenerateStairs(); // Generate stairs on the floor
    void GenerateEntities(); // Generate entities (enemies, items) on the floor
    void readFromStream(std::istream &is); // Read floor data from input stream
    Position target(Position curr, Direction dir); // Get the target position based on current position and direction
    bool isAdjacent(Position a, Position b); // Check if two positions are adjacent

};
