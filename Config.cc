export module config;

import <vector>;
import <map>;
import <utility>;
import position;
import enums;

namespace EnemyConfig {
    export inline const std::map<Race, int> enemyFrequency = {
        {Race::HUMAN,    4},
        {Race::DWARF,    3},
        {Race::HALFLING, 5},
        {Race::ELF,      2},
        {Race::ORCS,      2},
        {Race::MERCHANT, 2}
    };
    export inline const int MaxEnemiesPerFloor = 20;
}

namespace PotionConfig {
    export inline const std::map<PotionType, int> potionFrequency = {
        {PotionType::BA,   1},
        {PotionType::BD,   1},
        {PotionType::PH,   1},
        {PotionType::WA,   1},
        {PotionType::WD,   1},
        {PotionType::RH,   1}
    };
    export inline const int MaxPotionsPerFloor = 10;
}

namespace TreasureConfig {
    export inline const std::map<TreasureType, int> treasureFrequency = {
        {TreasureType::SMALL,    2},
        {TreasureType::NORMAL,   5},
        {TreasureType::DRAGON,   1}
    };
    export inline const int MaxTreasuresPerFloor = 10;
}
