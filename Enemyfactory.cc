export module enemyfactory;

import enemy;
import concreteenemies;
import chamber;
import enums;
import player;

export class EnemyFactory {
    Player &player; // reference to the player, if needed for enemy creation
  public:
    explicit EnemyFactory(Player &player);
    Enemy createEnemy(EnemyType type, Chamber &chamber);
};