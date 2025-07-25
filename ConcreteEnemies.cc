export module concreteenemies;

import enemy;
import enums;
import position;
import treasure;

/// Human enemy: standard opponent with no special abilities.
export class Human : public Enemy {
  public:
    Human(Position pos);
    ~Human();
};

/// Dwarf enemy: tanky opponent with high defense.
export class Dwarf : public Enemy {
  public:
    Dwarf(Position pos);
    ~Dwarf();
};

/// Elf enemy: agile attacker with special attack behavior.
export class Elf : public Enemy {
  public:
    Elf(Position pos);
    ~Elf();
    void attack(Character &target) override; // Override attack to handle special Elf behavior
};

/// Orc enemy: strong attacker with special attack behavior.
export class Orc : public Enemy {
  public:
    Orc(Position pos);
    ~Orc();
};

/// Merchant enemy: neutral until provoked, then hostile.
export class Merchant : public Enemy {
  public:
    inline static bool hostile = false; // Merchant's global hostile state
    Merchant(Position pos);
    ~Merchant();
    // Override onHit to handle hostile
    void onHit(Character &whoFrom) override;
    // Override attack to only attack if hostile
    void attack(Character &target) override;
};

/// Dragon enemy: guards a hoard, does not move.
export class Dragon : public Enemy {
  DragonHoard* hoard = nullptr;
  public:
    Dragon(Position pos);
    ~Dragon();
    // Override move to do nothing
    void move(Direction dir) override;
    // Set the non-ownership pointer to the hoard
    void setHoard(DragonHoard* dragonHoard);
    // return the hoard pointer
    DragonHoard* getHoard() const;
    // return true if hoard pointer is not null
    bool isGuarding() const;
};

/// Halfling enemy: elusive opponent with special behavior.
export class Halfling : public Enemy {
  public:
    Halfling(Position pos);
    ~Halfling();
};
