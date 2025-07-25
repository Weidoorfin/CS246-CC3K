export module concreteenemies;

import enemy;
import enums;
import position;

export class Human : public Enemy {
  public:
    Human(Position pos);
    ~Human();
};

export class Dwarf : public Enemy {
  public:
    Dwarf(Position pos);
    ~Dwarf();
};

export class Elf : public Enemy {
  public:
    Elf(Position pos);
    ~Elf();
    void attack(Character &target) override; // Override attack to handle special Elf behavior
};

export class Orc : public Enemy {
  public:
    Orc(Position pos);
    ~Orc();
    void attack(Character &target) override; // Override attack to handle special Orc behavior
};

export class Merchant : public Enemy {
  public:
    inline static bool hostile = false; // Merchant's global hostile state
    Merchant(Position pos);
    ~Merchant();
    void onHit(Character &whoFrom) override; // Override onHit to handle hostile
    void attack(Character &target) override; // override attack to only attack if hostile
};

export class Dragon : public Enemy {
  Position hoardpos;
  public:
    Dragon(Position pos);
    ~Dragon();
    void move(Direction dir) override; // Override move to do nothing
    void setHoardpos(Position pos);
    Position getHoardpos() const;
};

export class Halfling : public Enemy {
  public:
    Halfling(Position pos);
    ~Halfling();
};
