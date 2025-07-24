export module randomengine;

import <cstdint>;
import <vector>;
import <map>;
import <random>;
import <algorithm>;
import enums;
import PRNG;

constexpr uint32_t DEFAULT_GLOBAL_SEED = 696969;

export class RandomEngine {
    inline static uint32_t global_seed = DEFAULT_GLOBAL_SEED;
    inline static PRNG prng{DEFAULT_GLOBAL_SEED};
    inline static std::default_random_engine dre{DEFAULT_GLOBAL_SEED};

    // Frequency distribution of enemy based on their race
public:
    RandomEngine();

    void setSeed(uint32_t seed);
    uint32_t getSeed() const;

    bool chance(uint32_t prob); // produce true for prob% of times
    bool chance(int num, int denom); // produce true for num/denom of times
    std::vector<int> genIndices(int l, int u); // generate a shuffled vector of indices in the range [l, u)
    std::vector<Direction> genDirections(); // generate a shuffled vector of directions
    Race genEnemyRace(); // generate a random enemy based on the predefined probability distribution
    PotionType genPotionType(); // generate a random potion type based on the predefined probability distribution
    TreasureType genTreasureType(); // generate a random treasure type based on the
};

