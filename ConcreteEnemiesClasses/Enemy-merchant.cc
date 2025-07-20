export module merchant;

import enemy;
import chamber;
import enums;


export class Merchant : public Enemy {
 public:
    inline static bool hostile = false; // Merchant's global hostile state
    Merchant(Player &player, Chamber &chamber);
    ~Merchant();
    void onHit(Character &whoFrom) override; // Override onHit to handle hostile
    void update(Character &player) override;
}
