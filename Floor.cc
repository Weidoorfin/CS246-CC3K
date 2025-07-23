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

    getEmptyMap(std::istream &is); // Read an empty map from input stream
    void GenerateStairs(); // Generate stairs on the floor
    void GenerateEntities(); // Generate entities (enemies, items) on the floor
    void GeneratePlayerpos(); // Generate the player position on the floor
    void readFromStream(std::istream &is); // Read floor data from input stream

 public:
    explicit Floor(); // Default constructor
    explicit Floor(std::istream &is); // Constructor to read from input stream
    Floor(std::istream &is, int seed); // Constructor to read from input stream with seed

    // Accessories and mutators
    void setPlayer(std::unique_ptr<Player> p); // Set the player on the floor
    Position getStair() const; // Get the position of the stairs
    bool isComplete() const; // Check if the floor is complete
    int getLevel() const; // Get the level of the floor
    void setLevel(int level); // Set the level of the floor
    const vector<Chamber>& getChambers() const; // Get the chambers in the floor
    const vector<Enemy*>& getEnemies() const; // Get the enemies in the floor
    const vector<Item*>& getItems() const; // Get the items in the floor

    // Editing
    void addChamber(const Chamber &chamber); // Add a chamber to the floor
    void addEnemy(const Enemy &enemy); // Add an enemy to the floor
    void addItem(const Item &item); // Add an item to the floor
    void removeEnemy(const Enemy &enemy); // Remove an enemy from the floor
    void removeItem(const Item &item); // Remove an item from the floor

    // Player actions
    bool playerMove(Direction dir); // Move the player in a direction
    bool playerAttack(Direction dir); // Attack a character
    bool playerUseItem(Direction dir); // Use an item
    void enemyTurn(); // Perform enemy actions for the turn
    void handleEnemyDeath(Enemy* enemy); // Handle the death of an enemy

    // Floor management
    void readFromStream(std::istream &is); // Read floor data from an input stream
    void writeToStream(std::ostream &os) const; // Write floor data to an output stream
};
