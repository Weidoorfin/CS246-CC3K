export module chamber;


import <vector>;
import <utility>;
import position;
import randomengine;

export class Chamber {
    bool withPlayer = false;
    struct Status {
      Position pos;
      bool occupied;
    };
    std::vector<Status> validArea;
  public:
    // construct default chamber
    Chamber() = default;
    // Identify if the chamber is occupied by the player, used for random generation
    bool isWithPlayer() const;
    // Set the chamber to be occupied by the player, used for random generation
    void setWithPlayer();
    // Add a tile to the chamber, identified by Floor-impl.cc
    void addTile(Position pos);
    // Returns the Position that is a random tile in this chamber
    Position getRandomTile(); // produces a position of a random unoccupied tile in chamber
  private:
    // Checks if the tile is valid when random generating
    bool isValidTile(Status s);
};
