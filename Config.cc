export module config;

namespace EnemyConfig {
    export inline const std::map<Race, int> enemyFrequency = {
        {Race::HUMAN,    4},
        {Race::DWARF,    3},
        {Race::HALFLING, 5},
        {Race::ELF,      2},
        {Race::ORC,      2},
        {Race::MERCHANT, 2}
    };
    export inline const int MaxEnemiesPerFloor = 20;
}
