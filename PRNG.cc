// External module providing a simple pseudo-random number generator.
export module PRNG;

import <cstdint>;
import <cassert>;

// A simple linear-congruential PRNG with customizable seed.
export class PRNG {
    uint32_t seed_;
public:
    // Constructs a PRNG with the given seed.
    PRNG(uint32_t s = 696969) {
        seed_ = s;
        assert(seed_ != 0 && "invalid seed");
    }

    // Returns the current seed value.
    uint32_t seed() { return seed_; }

    // Resets the generator with a new seed.
    void seed(uint32_t s) {
        seed_ = s;
        assert(seed_ != 0 && "invalid seed");
    }

    // Generates the next pseudorandom 32-bit value.
    uint32_t operator()() {
        seed_ = 36969 * (seed_ & 65535) + (seed_ >> 16);
        return seed_;
    }

    // Generates a random integer in the range [0, u].
    uint32_t operator()(uint32_t u) {
        assert(u < (uint32_t)-1 && "invalid random range");
        return operator()() % (u + 1);
    }

    // Generates a random integer in the range [l, u]
    uint32_t operator()(uint32_t l, uint32_t u) {
        assert(l <= u && "invalid random range");
        return operator()(u - l) + l;
    }
};
