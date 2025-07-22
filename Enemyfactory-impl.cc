module enemyfactory;

import enemy;
import concreteenemies;
import position;
import enums;

Enemy EnemyFactory::createEnemy(EnemyType type, Position pos) {
    switch (type) {
        case EnemyType::DRAGON:
            return std::make_unique<Dragon>(pos);
        case EnemyType::DWARF:
            return std::make_unique<Dwarf>(pos);
        case EnemyType::ELF:
            return std::make_unique<Elf>(pos);
        case EnemyType::HALFLING:
            return std::make_unique<Halfling>(pos);
        case EnemyType::HUMAN:
          return std::make_unique<Human>(pos);
    }
}
