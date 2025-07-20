module goblin;

Goblin::Goblin() : Player(PlayerRace::GOBLIN) {
    maxHP = 110;
    atk = 15;
    def = 20;
    currentHP = maxHP;
}

void Goblin::onKill() override {
    gainGold(5);
}