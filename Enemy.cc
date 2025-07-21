export module enemy;

import enums;
import character;
import position;

export class Enemy: public Character {
    EnemyType type;
    void randomMove();
    bool isInRange(Position pos) const;
    void attack(); // auto attack the player, if player is in range
  public:
    Enemy(EnemyType type, int maxHP, int atk, int def);
    virtual void update(); // update enemy state based on player's position, has a default implementation
    virtual ~Enemy() = default; // default destructor
};

