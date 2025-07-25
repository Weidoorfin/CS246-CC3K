export module enemyfactory;

import <memory>;
import enums;
import position;
import enemy;
import concreteenemies;

// Enemy factory class
export class EnemyFactory {
  public:
    EnemyFactory();
    // Factory method that returns an enemy of the required race
    std::unique_ptr<Enemy> createEnemy(Race race, Position pos);
};
