export module floor;

import <vector>;

import chamber;
import enemy;
import item;
import position;
import abstractos;

export class Floor : public Subject, public Observer {
    Position stair;
    bool complete;
    vector<Chamber> chambers;
    EnemyEngine enemyEngine;
    vector<Item> items;
 public:
    Floor() = default; // Default constructor
    Floor(std::istream &is); // Constructor to read from input stream
    void attach(Observer *obs) override; // Attach an observer
    void detach(Observer *obs) override; // Detach an observer
    void notify() override; // Notify observers of changes
    void update(Subject *subject) override; // Update method for observer pattern
    Position getStair() const; // Get the position of the stairs
    void setStair(const Position &pos); // Set the position of the stairs
    bool isComplete() const; // Check if the floor is complete
    void setComplete(bool status); // Set the completion status of the floor
    int getLevel() const; // Get the level of the floor
    void setLevel(int lvl); // Set the level of the floor
    const vector<Chamber>& getChambers() const; // Get the chambers in the floor
    const vector<Enemy>& getEnemies() const; // Get the enemies in the floor
    const vector<Item>& getItems() const; // Get the items in the floor
    void addChamber(const Chamber &chamber); // Add a chamber to the floor
    void addEnemy(const Enemy &enemy); // Add an enemy to the floor
    void addItem(const Item &item); // Add an item to the floor
    void removeEnemy(const Enemy &enemy); // Remove an enemy from the floor
    void removeItem(const Item &item); // Remove an item from the floor
    void readFromStream(std::istream &is); // Read floor data from an input stream
    void writeToStream(std::ostream &os) const; // Write floor data to an output stream
    friend std::istream &operator>>(std::istream &is, Floor &fl); // Overloaded input operator for reading floor data
    friend std::ostream &operator<<(std
};
