module concreteplayer;

import <memory>;
import <cmath>;
import position;
import player;
import enums;
import character;
import randomengine;

Shade::Shade() : Player(Race::SHADE, 150, 25, 25, position) {
}

double Shade::getScore() const {
    return std::round(totGold * 1.5); 
}

std::unique_ptr<Player> Shade::reset() {
    return std::make_unique<Shade>(*this);
}

Drow::Drow() : Player{Race::DROW, 150, 25, 15, position} {
    currentHP = maxHP;
}


std::unique_ptr<Player> Drow::reset() {
    return std::make_unique<Drow>(*this);
}

double Drow::getPotionMultiplier() const {
    return 1.5;
}

Vampire::Vampire() : Player{Race::VAMPIRE, 50, 25, 25, position} {
    currentHP = maxHP;
}


void Vampire::gainHP(int inc) {
    currentHP += inc;
}

void Vampire::attack(Character &target) {
    if (target.getRace() == Race::HALFLING) {
        RandomEngine rng;
        // Halflings have a 50% chance to dodge the attack
        if (rng.chance(50)) {
            return;
        }
    }
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



Goblin::Goblin() : Player{Race::GOBLIN, 110, 15, 20, position} {
    currentHP = maxHP;
}

void Goblin::attack(Character &target) {
    if (target.getRace() == Race::HALFLING) {
        RandomEngine rng;
        if (rng.chance(50)) {
            return;
        }
    }
    target.onHit(*this);
    if(!target.isAlive()) {
        gainGold(5); // Gain 5 gold if the target is killed
    }
}

void Goblin::onHit(Character &whoFrom) {
    int damage = std::ceil((100 / (100 + whoFrom.getDef())) * whoFrom.getAtk());
    loseHP(damage);
    if (whoFrom.getRace() == Race:ORC) {
        loseHP(static_cast<int>(std::round(damage * 1.5)));
    } else {
        loseHP(damage);
    }
}

std::unique_ptr<Player> Goblin::reset() {
    return std::make_unique<Goblin>(*this);
}

Troll::Troll() : Player{Race::TROLL, 120, 25, 15, position} {
    currentHP = maxHP;
}

void Troll::onTurn() {
    currentHP = (currentHP + 5 <= maxHP)? currentHP + 5 : maxHP;
}

std::unique_ptr<Player> Troll::reset() {
    return std::make_unique<Troll>(*this);
}

