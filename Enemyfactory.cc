export module enemyfactory;

import <memory>;
import enums;
import position;
import enemy;
import concreteenemies;

export class EnemyFactory {
  public:
    explicit EnemyFactory();
    std::unique_ptr<Enemy> createEnemy(Race race, Position pos);
};