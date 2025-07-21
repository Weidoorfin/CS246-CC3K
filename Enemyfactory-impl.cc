module enemyfactory;

import enemy;
import concreteenemies;
import enums;

Enemy EnemyFactory::createEnemy(EnemyType type) {
    switch (type) {
        case EnemyType::DRAGON:
            return Dragon();
        case EnemyType::DWARF:
            return Dwarf();
        case EnemyType::ELF:
            return Elf();
        case EnemyType::HALFLING:
            return Halfling();
        case EnemyType::HUMAN:
          return Human();
    }
}
