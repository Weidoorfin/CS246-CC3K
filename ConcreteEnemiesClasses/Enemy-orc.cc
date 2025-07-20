export module orc;

import enemy;
import chamber;
import enums;


export class Orc : public Enemy {
 public:
    Orc(Player &player, Chamber &chamber);
    ~Orc();
}
