export module human;

import enemy;
import chamber;
import enums;


export class Human : public Enemy {
 public:
    Human(Player &player, Chamber &chamber);
    ~Human();
}
