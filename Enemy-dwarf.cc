export module dwarf;

import enemy;
import chamber;
import enums;


export class Dwarf : public Enemy {
 public:
    Dwarf(Player &player, Chamber &chamber);
    ~Dwarf();
}
