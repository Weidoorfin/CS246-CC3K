module floor;

import <fstream>;
import <vector>;

void Floor::getEmptyMap(std::istream &is) {
    // Implementation for reading an empty map from the input stream
    // This will populate the grid and tileTypes with initial values
}

void Floor::GenerateStairs() {
    // Implementation for generating stairs on the floor
}

void Floor::GenerateEntities() {
    // Implementation for generating entities (enemies, items) on the floor
}

void Floor::GeneratePlayer() {
    // Implementation for generating the player on the floor
}

Floor::Floor(){
    // Initialize the grid with empty chambers
    ifstream emptyMap("emptyfloor.txt");
    getEmptyMap(emptyMap);
    GenerateStairs();
    GenerateEntities();
    GeneratePlayer();
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



bool Floor::isComplete() const {
    return complete;
}


// enemy具体的attack和move的逻辑（比如merchant非hostile时不攻击，dragon不移动）由method override来实现，
// floor只要满足条件就call attack和move。
//////////////////////////////////////////////////////////////
// Some previously-implemented enemy methods to make reference to:
import <random>;
import <algorithm>;
import <chrono>;
// Helper function to generate a random vector of unique directions
// this random array can be used in randomMove to try moving in a random direction
// until a valid move is found.
vector<Direction> genDirections() {
    std::vector<Direction> directions {
        Direction::N, Direction::NE, Direction::E, Direction::SE,
        Direction::S, Direction::SW, Direction::W, Direction::NW
    };
    // default time-based seed
    uint32_t seed = std::chrono::system_clock::now().time_since_epoch().count();
    // Set seed to global seed variable if it exists
    if (global_seed != 0) {
        seed = global_seed;
    }
    std::default_random_engine rng{seed};
    std::shuffle(directions.begin(), directions.end(), rng);
    return directions; // return a random direction
}

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