export module troll;

import player;

export class Troll : public Player {
public:
    Troll();
    ~Troll() = default;

    void onTurn() override;  // Called every turn to add HP
};