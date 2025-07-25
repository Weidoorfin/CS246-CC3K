export module enemy;

import enums;
import character;
import position;

// Abstract Enemy class
export class Enemy: public Character {
  bool moveToggle = false;
  static bool globalMoveDisabled;
  public:
    Enemy(Race race, int maxHP, int atk, int def, char symbol, int colour, Position pos);
    virtual ~Enemy() = 0;
    // set moveToggle to true, indicating enemy has moved in the current turn
    void toggleMove(); 
    // return the moveToggle
    bool getmoveToggle() const;
    // set MoveToggle to false
    void resetMoveToggle();
    // toggle globalMoveDisabled
    static void toggleGlobalMovement();
    // return true if global movement is disabled
    static bool isGlobalMovementDisabled();
};
