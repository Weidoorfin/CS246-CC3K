export module enemy;

import enums;
import character;
import position;

export class Enemy: public Character {
  bool moveToggle = false;
  static bool globalMoveDisabled;
  public:
    Enemy(Race race, int maxHP, int atk, int def, char symbol, int colour, Position pos);
    virtual ~Enemy() = default; // default destructor
    void toggleMove(); // set move toggle to true
    bool getmoveToggle() const;
    void resetMoveToggle();
    static void toggleGlobalMovement();
    static bool isGlobalMovementDisabled();
};
