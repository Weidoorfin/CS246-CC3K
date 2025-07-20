export module elf;

import enemy;
import chamber;
import enums;


export class Elf : public Enemy {
 public:
    Elf(Player &player, Chamber &chamber);
    ~Elf();
}
