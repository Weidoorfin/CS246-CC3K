module concreteplayer;

import player;

Shade::Shade() : Player{PlayerRace::SHADE} {
    maxHP = 125;
    atk = 25;
    def = 25;
    currentHP = maxHP;
}

double Shade::getScore() const {
    return Gold * 1.5; 
}

Drow::Drow() : Player{PlayerRace::DROW} {
    maxHP = 150;
    atk = 25;
    def = 15;
    currentHP = maxHP;
}

std::unique_ptr<Player> Drow::reset() {
    return std::make_unique<Drow>(*this);
}

Vampire::Vampire() : Player(PlayerRace::VAMPIRE) {
    maxHP = 50;
    atk = 25;
    def = 25;
    currentHP = 50;
}
// (50 HP, 25 Atk, 25 Def, gains 5 HP every successful attack and has no maximum HP) 
// override onHit() and attack() behavior so it doesn't clamp HP increases.

void Vampire::gainHP(int inc) {
    currentHP += inc;
}

std::unique_ptr<Player> Vampire::reset() {
    return std::make_unique<Vampire>(*this);
}



Goblin::Goblin() : Player(PlayerRace::GOBLIN) {
    maxHP = 110;
    atk = 15;
    def = 20;
    currentHP = maxHP;
}

void Goblin::onKill() {
    gainGold(5);
}

std::unique_ptr<Player> Goblin::reset() {
    return std::make_unique<Goblin>(*this);
}

Troll::Troll() : Player(PlayerRace::TROLL) {
    maxHP = 120;
    atk = 25;
    def = 15;
    currentHP = maxHP;
}

void Troll::onTurn() {
    currentHP = (currentHP + 5 <= maxHP)? currentHP + 5 : maxHP;
}

std::unique_ptr<Player> Troll::reset() {
    return std::make_unique<Troll>(*this);
}