module randomengine;

import <cstdint>;
import <vector>;
import <map>;
import <random>;
import <algorithm>;
import <utility>;
import PRNG;
import config;


RandomEngine::RandomEngine() {}

void RandomEngine::setSeed(uint32_t seed) {
    global_seed = seed;
    prng.seed(seed);
    dre.seed(seed);
}

uint32_t RandomEngine::getSeed() const {
    return global_seed;
}

std::vector<Direction> RandomEngine::genDirections() {
    std::vector<Direction> directions {
        Direction::N, Direction::NE, Direction::E, Direction::SE,
        Direction::S, Direction::SW, Direction::W, Direction::NW
    };
    std::shuffle(directions.begin(), directions.end(), dre);
    return directions; // return a random direction
}

bool RandomEngine::chance(uint32_t prob) {
    // Check if the probability is within valid range
    if (prob > 100) {
        prob = 100; // Invalid probability, return false
    }
    return prng(100) < prob; // return true with prob% chance
}

bool RandomEngine::chance(int num, int denom) {
    if (denom <= 0 || num < 0 || num > denom) {
        return false; // Invalid fraction, return false
    }
    std::vector<int> chances(denom, 0); // vector fill constructor
    std::fill(chances.begin(), chances.begin() + num, 1); // Fill with 1s for success
    std::shuffle(chances.begin(), chances.end(), dre);
    return chances[0];
}

// requires l <= u
std::vector<int> RandomEngine::genIndices(int l, int u) {
    if (l > u) {
        std::swap(l, u);
    }
    std::vector<int> indices(u - l + 1);
    for (int i = l; i <= u; ++i) {
        indices[i - l] = i;
    }
    std::shuffle(indices.begin(), indices.end(), dre);
    return indices; // return a shuffled vector of indices in the range [l, u]
}

Race RandomEngine::genEnemyRace() {
    // calculate total frequency
    int total_freq = 0;
    for (const auto& [key, value] : EnemyConfig::enemyFrequency) {
        total_freq += value;
    }
    std::vector<Race> result;
    // build frequency array
    for (const auto& [key, value] : EnemyConfig::enemyFrequency) {
        for (int i = 0; i < value; ++i) {
            result.push_back(key);
        }
    }
    // Shuffle the result to randomize the selection
    std::shuffle(result.begin(), result.end(), dre);
    return result[0]; // return a random
}

PotionType RandomEngine::genPotionType() {
    // calculate total frequency
    int total_freq = 0;
    for (const auto& [key, value] : PotionConfig::potionFrequency) {
        total_freq += value;
    }
    std::vector<PotionType> result;
    // build frequency array
    for (const auto& [key, value] : PotionConfig::potionFrequency) {
        for (int i = 0; i < value; ++i) {
            result.push_back(key);
        }
    }
    // Shuffle the result to randomize the selection
    std::shuffle(result.begin(), result.end(), dre);
    return result[0]; // return a random potion type
}

TreasureType RandomEngine::genTreasureType() {
    // calculate total frequency
    int total_freq = 0;
    for (const auto& [key, value] : TreasureConfig::treasureFrequency) {
        total_freq += value;
    }
    std::vector<TreasureType> result;
    // build frequency array
    for (const auto& [key, value] : TreasureConfig::treasureFrequency) {
        for (int i = 0; i < value; ++i) {
            result.push_back(key);
        }
    }
    // Shuffle the result to randomize the selection
    std::shuffle(result.begin(), result.end(), dre);
    return result[0]; // return a random treasure type
}


FloorName RandomEngine::genFloorName() {
    // calculate total frequency
    int total_freq = 0;
    for (const auto& [key, value] : FloorConfig::floorFrequency) {
        total_freq += value;
    }
    std::vector<FloorName> result;
    // build frequency array
    for (const auto& [key, value] : FloorConfig::floorFrequency) {
        for (int i = 0; i < value; ++i) {
            result.push_back(key);
        }
    }
    // Shuffle the result to randomize the selection
    std::shuffle(result.begin(), result.end(), dre);
    return result[0]; // return a random treasure type
}
