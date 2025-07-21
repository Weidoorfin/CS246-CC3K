export module concreteplayer;

import player;
import enums;

export class Shade: public Player {
public:
    Shade(Position pos = Position{0, 0});
    ~Shade() = default; 
    double getScore() const override;
    std::unique_ptr<Player> reset() const override;
};

export class Drow: public Player {
public:
    Drow(Position pos = Position{0, 0});
    ~Drow() = default;
    std::unique_ptr<Player> reset() const override;
};

export class Vampire : public Player {
public:
    Vampire(Position pos = Position{0, 0});
    ~Vampire() = default;
    void gainHP(int inc) override;
    void attack(Character &target) override;
    std::unique_ptr<Player> reset() const override;
};

export class Goblin : public Player {
public:
    Goblin(Position pos = Position{0, 0});
    ~Goblin() = default;
    void attack(Character &target) override;
    std::unique_ptr<Player> reset() const override;
};


export class Troll : public Player {
public:
    Troll(Position pos = Position{0, 0});
    ~Troll() = default;
    void onTurn() override;  // Called every turn to add HP
    std::unique_ptr<Player> reset() const override;
};