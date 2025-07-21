export module enemyfactory;

import enemy;
import concreteenemies;
import position;
import enums;

export class EnemyFactory {
  public:
    explicit EnemyFactory();
    Enemy createEnemy(EnemyType type, Position pos);
};