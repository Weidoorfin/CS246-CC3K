export module goblin;

import player;

export class Goblin : public Player {
public:
    Goblin();
    ~Goblin = default;
    void onKill(Character &enemy) override;

};