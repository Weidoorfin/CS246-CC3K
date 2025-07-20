export module dragon;

import enemy;
import chamber;
import enums;


export class Dragon : public Enemy {
 public:
    Dragon(Player &player, Chamber &chamber);
    ~Dragon();
}