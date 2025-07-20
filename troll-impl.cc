module troll;

Troll::Troll() : Player(PlayerRace::TROLL) {
    maxHP = 120;
    atk = 25;
    def = 15;
    currentHP = maxHP;
}

void Troll::onTurn() {
    currentHP = (currentHP + 5 <= maxHP)? currentHP + 5 : maxHP;
}
