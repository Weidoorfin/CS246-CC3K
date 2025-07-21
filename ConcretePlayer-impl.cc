module concreteplayer;

import player;

Shade::Shade() : Player(PlayerRace::SHADE, 150, 25, 25, position) {
}

double Shade::getScore() const {
    return totGold * 1.5; 
}

std::unique_ptr<Player> Shade::reset() {
    return std::make_unique<Shade>(*this);
}

Drow::Drow() : Player{PlayerRace::DROW, 150, 25, 15, position} {
    currentHP = maxHP;
}


std::unique_ptr<Player> Drow::reset() {
    return std::make_unique<Drow>(*this);
}

Vampire::Vampire() : Player{PlayerRace::VAMPIRE, 50, 25, 25, position} {
    currentHP = maxHP;
}


void Vampire::gainHP(int inc) {
    currentHP += inc;
}

void Vampire::attack(Character &target) {
    target.onHit(*this);
    if (target.getRace() == EnemyType::DWARF) {
        loseHP(5); // Lose 5 HP if attacking a dwarf
    } else {
        gainHP(5); // Otherwise, gain 5 HP
    }
}


std::unique_ptr<Player> Vampire::reset() {
    return std::make_unique<Vampire>(*this);
}



Goblin::Goblin() : Player{PlayerRace::GOBLIN, 110, 15, 20, position} {
    currentHP = maxHP;
}

void Goblin::attack(Character &target) {
    target.onHit(*this);
    if(!target.isAlive()) {
        gainGold(5); // Gain 5 gold if the target is killed
    }
}

std::unique_ptr<Player> Goblin::reset() {
    return std::make_unique<Goblin>(*this);
}

Troll::Troll() : Player{PlayerRace::TROLL, 120, 25, 15, position} {
    currentHP = maxHP;
}

void Troll::onTurn() {
    currentHP = (currentHP + 5 <= maxHP)? currentHP + 5 : maxHP;
}

std::unique_ptr<Player> Troll::reset() {
    return std::make_unique<Troll>(*this);
}

