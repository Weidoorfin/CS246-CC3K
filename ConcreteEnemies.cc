export module concreteenemies;

import enemy;
import chamber;
import enums;

export class Human : public Enemy {
 public:
    Human(Player &player, Chamber &chamber);
    ~Human();
}

export class Dwarf : public Enemy {
 public:
    Dwarf(Player &player, Chamber &chamber);
    ~Dwarf();
}

export class Elf : public Enemy {
 public:
    Elf(Player &player, Chamber &chamber);
    ~Elf();
}

export class Orc : public Enemy {
 public:
    Orc(Player &player, Chamber &chamber);
    ~Orc();
}

export class Merchant : public Enemy {
 public:
    inline static bool hostile = false; // Merchant's global hostile state
    Merchant(Player &player, Chamber &chamber);
    ~Merchant();
    void onHit(Character &whoFrom) override; // Override onHit to handle hostile
    void update(Character &player) override;
}

export class Dragon : public Enemy {
 public:
    Dragon(Player &player, Chamber &chamber);
    ~Dragon();
}

export class Halfling : public Enemy {
 public:
    Halfling(Player &player, Chamber &chamber);
    ~Halfling();
}
