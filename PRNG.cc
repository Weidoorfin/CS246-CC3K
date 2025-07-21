// PRNG.cc
export module PRNG;

import <cstdint>;
import <cassert>;

export uint32_t global_seed = 123456789; // Default seed value

export class PRNG {
    uint32_t seed_;
public:
    PRNG(uint32_t s = 362436069) {
        seed_ = s;
        assert(seed_ != 0 && "invalid seed");
    }

    uint32_t seed() { return seed_; }

    void seed(uint32_t s) {
        seed_ = s;
        assert(seed_ != 0 && "invalid seed");
    }

    uint32_t operator()() {
        seed_ = 36969 * (seed_ & 65535) + (seed_ >> 16);
        return seed_;
    }

    uint32_t operator()(uint32_t u) {
        assert(u < (uint32_t)-1 && "invalid random range");
        return operator()() % (u + 1);
    }

    uint32_t operator()(uint32_t l, uint32_t u) {
        assert(l <= u && "invalid random range");
        return operator()(u - l) + l;
    }
};

