export module halfling;

import enemy;
import chamber;
import enums;


export class Halfling : public Enemy {
 public:
    Halfling(Player &player, Chamber &chamber);
    ~Halfling();
}
