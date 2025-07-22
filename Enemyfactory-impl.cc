module enemyfactory;

import enemy;
import concreteenemies;
import position;
import enums;

Enemy EnemyFactory::createEnemy(Race race, Position pos) {
    switch (race) {
        case Race::DRAGON:
            return std::make_unique<Dragon>(pos);
        case Race::DWARF:
            return std::make_unique<Dwarf>(pos);
        case Race::ELF:
            return std::make_unique<Elf>(pos);
        case Race::HALFLING:
            return std::make_unique<Halfling>(pos);
        case Race::HUMAN:
          return std::make_unique<Human>(pos);
    }
}
