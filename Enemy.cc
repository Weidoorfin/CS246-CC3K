export module enemy;

import enums;
import character;
import subject;
import position;
import player;

export class Enemy: public Character {
    EnemyType type;
    Player &player;
    void randomMove();
    bool isInRange(Position pos) const;
    void attack(); // auto attack the player, if player is in range
  public:
    Enemy(EnemyType type, Player &player, Chamber &chamber, int maxHP, int atk, int def);
    virtual void update(); // update enemy state based on player's position, has a default implementation
    virtual ~Enemy() = default; // default destructor
};

