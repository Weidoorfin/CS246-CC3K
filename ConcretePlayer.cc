export module concreteplayer;

import <string>;
import <memory>;
import position;
import player;
import enums;
import character;

export class Shade: public Player {
public:
    Shade(Position pos = Position{0, 0});
    ~Shade() = default; 

    // Shade gets bonus 50% of totGold
    double getScore() const override;
    std::unique_ptr<Player> reset() const override;
    std::string getRaceName() const override;
};

export class Drow: public Player {
public:
    Drow(Position pos = Position{0, 0});
    ~Drow() = default;
    std::unique_ptr<Player> reset() const override;

    // Drow gets 1.5x potion effect
    double getPotionMultiplier() const override;
    std::string getRaceName() const override;
};

export class Vampire : public Player {
public:
    Vampire(Position pos = Position{0, 0});
    ~Vampire() = default;

    // Vampire doe not have maxHP, so it can gain HP indefinitely
    void gainHP(int inc) override;

    // gains 5 HP for every successful attack except against Dwarf
    void attack(Character &target) override;
    std::unique_ptr<Player> reset() const override;
    std::string getRaceName() const override;
};

export class Goblin : public Player {
public:
    Goblin(Position pos = Position{0, 0});
    ~Goblin() = default;

    // gets 5 gold when it kills an enemy
    void attack(Character &target) override;

    // gets 50% more damage if got hit from ORC
    void onHit(Character &whoFrom) override;
    std::unique_ptr<Player> reset() const override;
    std::string getRaceName() const override;
};


export class Troll : public Player {
public:
    Troll(Position pos = Position{0, 0});
    ~Troll() = default;

    // Called every turn to add HP
    void onTurn() override;  
    std::unique_ptr<Player> reset() const override;
    std::string getRaceName() const override;
};
