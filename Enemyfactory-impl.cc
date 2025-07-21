module enemyfactory;

import enemy;
import concreteenemies;
import position;
import enums;

Enemy EnemyFactory::createEnemy(EnemyType type, Position pos) {
    switch (type) {
        case EnemyType::DRAGON:
            return Dragon(Position pos);
        case EnemyType::DWARF:
            return Dwarf(Position pos);
        case EnemyType::ELF:
            return Elf(Position pos);
        case EnemyType::HALFLING:
            return Halfling(Position pos);
        case EnemyType::HUMAN:
          return Human(Position pos);
    }
}
