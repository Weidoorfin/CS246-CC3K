export module concreteenemies;

import enemy;
import enums;

export class Human : public Enemy {
 public:
    Human();
    ~Human();
}

export class Dwarf : public Enemy {
 public:
    Dwarf();
    ~Dwarf();
}

export class Elf : public Enemy {
 public:
    Elf();
    ~Elf();
}

export class Orc : public Enemy {
 public:
    Orc();
    ~Orc();
}

export class Merchant : public Enemy {
 public:
    inline static bool hostile = false; // Merchant's global hostile state
    Merchant();
    ~Merchant();
    void onHit(Character &whoFrom) override; // Override onHit to handle hostile
}

export class Dragon : public Enemy {
 public:
    Dragon();
    ~Dragon();
}

export class Halfling : public Enemy {
 public:
    Halfling();
    ~Halfling();
}
