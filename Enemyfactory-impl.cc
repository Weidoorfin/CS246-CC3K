module enemyfactory;

import <memory>;
import enemy;
import concreteenemies;
import position;
import enums;

EnemyFactory::EnemyFactory() {}

std::unique_ptr<Enemy> EnemyFactory::createEnemy(Race race, Position pos) {
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
        case Race::MERCHANT:
          return std::make_unique<Merchant>(pos);
        case Race::ORC:
          return std::make_unique<Orc>(pos);
        default:
            throw std::invalid_argument("Unknown race");
    }
}
