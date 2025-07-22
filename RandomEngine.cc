export module randomengine;

import <cstdint>;
import <vector>;
import <map>;
import <chrono>;
import <random>;
import <algorithm>;
import <chrono>;
import enums;


export class RandomEngine {
    inline static uint32_t global_seed = 0;
    // Frequency distribution of enemy based on their race
public:
    RandomEngine();

    void setRandomSeed(); // set a time based seed
    void setSeed(uint32_t seed);
    uint32_t getSeed() const;

    bool chance(int prob) const; // produce true for prob% of times
    bool chance(int num, int denom) const; // produce true for num/denom of times
    std::vector<Direction> genDirections() const; // generate a shuffled vector of directions
    Race genEnemyRace() const; // generate a random enemy based on the predefined probability distribution
    // takes in a 2D vector of entities and returns a random position within the bounds of the vector
    Position genPosition(vector<vector<entity*>> tiles) const; 
};

