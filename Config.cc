/**
 * Configuration module defining spawn frequencies and limits for 
 * enemies, potions, and treasures.
 */
export module config;

import <vector>;
import <map>;
import <utility>;
import position;
import enums;



// Configuration values for enemy spawn frequencies and maximum count per floor.
namespace EnemyConfig {
    // Mapping from each Race to its spawn frequency weight.
    export inline const std::map<Race, int> enemyFrequency = {
        {Race::HUMAN,    4},
        {Race::DWARF,    3},
        {Race::HALFLING, 5},
        {Race::ELF,      2},
        {Race::ORC,      2},
        {Race::MERCHANT, 2}
    };
    // Maximum number of enemies allowed per floor.
    export inline const int MaxEnemiesPerFloor = 20;
}

// Configuration values for potion spawn frequencies and maximum count per floor.
namespace PotionConfig {
    // Mapping from each PotionType to its spawn frequency weight.
    export inline const std::map<PotionType, int> potionFrequency = {
        {PotionType::BA,   1},
        {PotionType::BD,   1},
        {PotionType::PH,   1},
        {PotionType::WA,   1},
        {PotionType::WD,   1},
        {PotionType::RH,   1}
    };
    // Maximum number of potions allowed per floor.
    export inline const int MaxPotionsPerFloor = 10;
}

// Configuration values for treasure spawn frequencies and maximum count per floor.
namespace TreasureConfig {
    // Mapping from each TreasureType to its spawn frequency weight.
    export inline const std::map<TreasureType, int> treasureFrequency = {
        {TreasureType::SMALL,    2},
        {TreasureType::NORMAL,   5},
        {TreasureType::DRAGON,   1}
    };
    // Maximum number of treasures allowed per floor.
    export inline const int MaxTreasuresPerFloor = 10;
}
