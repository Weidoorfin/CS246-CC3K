export module enemyfactory;

import enemy;
import concreteenemies;
import chamber;
import enums;

export class EnemyFactory {
  public:
    explicit EnemyFactory();
    Enemy createEnemy(EnemyType type);
};