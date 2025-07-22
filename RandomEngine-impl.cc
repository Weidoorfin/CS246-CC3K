module randomengine;

import <cstdint>;
import <vector>;
import <random>;
import <algorithm>;
import <chrono>;
import PRNG;


RandomEngine::RandomEngine() {}

void RandomEngine::setRandomSeed() {
    global_seed = std::chrono::system_clock::now().time_since_epoch().count();
}

void RandomEngine::setSeed(uint32_t seed) {
    global_seed = seed;
}

uint32_t RandomEngine::getSeed() const {
    return global_seed;
}

vector<Direction> RandomEngine::genDirections() {
    if (global_seed == 0) {
        setRandomSeed(); // Ensure a seed is set if not already
    }
    std::vector<Direction> directions {
        Direction::N, Direction::NE, Direction::E, Direction::SE,
        Direction::S, Direction::SW, Direction::W, Direction::NW
    };
    std::default_random_engine rng{global_seed};
    std::shuffle(directions.begin(), directions.end(), rng);
    return directions; // return a random direction
}

bool RandomEngine::chance(int prob) const {
    PRNG rng{global_seed};
    // Check if the probability is within valid range
    if (prob < 0 || prob > 100) {
        return false; // Invalid probability, return false
    }
    return rng(100) < prob; // return true with prob% chance
}