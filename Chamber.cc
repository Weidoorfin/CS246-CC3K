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
    Chamber() = default;
    bool isWithPlayer() const;
    void setWithPlayer();
    void addTile(Position pos);
    Position getRandomTile(); // produces a position of a random unoccupied tile in chamber
    bool isValidTile(Status s);
};
