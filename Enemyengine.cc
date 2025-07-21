export module enemyengine;

import <vector>;
import enemy;
import concreteenemies;
import enemyfactory;
import chamber;
import player;

// A class to manage centralize enemy behaviours
// responsible for enemy creation, updates and all enemy-related operations
export class EnemyEngine {
    std::vector<Enemy> enemies; // List of enemies in the game
    Player &player; // Reference to the player
    chamber::Chamber &chamber; // Reference to the chamber where enemies are located
    EnemyFactory factory; // Factory to create enemies
    bool moveToggle = false; // Toggle for enemy movement

  public:
    EnemyEngine(EnemyFactory &factory, Player &player, Chamber chamber) {
        
    }

}