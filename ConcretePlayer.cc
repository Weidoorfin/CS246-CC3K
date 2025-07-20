export module concreteplayer;

import player;
import enums;

export class Shade: public Player {
public:
    Shade();
    ~Shade() = default; 
};

export class Drow: public Player {
public:
    Drow();
    ~Drow() = default;
}

export class Vampire : public Player {
public:
    Vampire();
    ~Vampire() = default;
    void gainHP(int inc) override;
};

export class Goblin : public Player {
public:
    Goblin();
    ~Goblin() = default;
    void onKill(Character &enemy) override;

};


export class Troll : public Player {
public:
    Troll();
    ~Troll() = default;

    void onTurn() override;  // Called every turn to add HP
};