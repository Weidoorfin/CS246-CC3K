module enemyfactory;

import enemy;
import enums;
import chamber;

Enemy EnemyFactory::createEnemy(EnemyType type, Chamber &chamber) {
    switch (type) {
        case EnemyType::DRAGON:
            return Dragon{player, chamber};
        case EnemyType::DWARF:
            return Dwarf{player, chamber};
        case EnemyType::ELF:
            return Elf{player, chamber};
        case EnemyType::HALFLING:
            return Halfling{player, chamber};
        case EnemyType::HUMAN:
            return Human{player, chamber};
    }
}
