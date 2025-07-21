export module enemyengine;

import <vector>;
import enemy;
import concreteenemies;
import enemyfactory;

// A class to manage enemy creation, updates and all enemy-related operations
export class EnemyEngine {
    std::vector<Enemy> enemies; // List of enemies in the game
    EnemyFactory factory; // Factory to create enemies

  public:
    EnemyEngine(Player &player) : factory(player) {}

    // Create an enemy of a specific type and add it to the list
    void createEnemy(EnemyType type, Chamber &chamber) {
        enemies.push_back(factory.createEnemy(type, chamber));
    }

    // Update all enemies, e.g., move them or make them attack
    void updateEnemies() {
        for (auto &enemy : enemies) {
            enemy.update();
        }
    }

    // Get the list of enemies
    const std::vector<Enemy>& getEnemies() const {
        return enemies;
    }
}