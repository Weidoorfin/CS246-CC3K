export module randomengine;

import <cstdint>;
import <vector>;
import <chrono>;
import <random>;
import <algorithm>;
import <chrono>;
import enums;

export class RandomEngine {
    inline static uint32_t global_seed = 0;
public:
    RandomEngine();

    void setRandomSeed(); // set a time based seed
    void setSeed(uint32_t seed);
    uint32_t getSeed() const;

    std::vector<Direction> genDirections() const;
    bool chance(int prob) const; // produce true for prob% chance
};

