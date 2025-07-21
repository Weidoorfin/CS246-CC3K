export module enemy;

import enums;
import character;
import position;

export class Enemy: public Character {
    EnemyType type; 
  public:
    Enemy(EnemyType type, int maxHP, int atk, int def, char symbol, int colour, Position pos);
    virtual ~Enemy() = default; // default destructor
};
