module concreteplayer;

import <string>;
import <memory>;
import <cmath>;
import position;
import player;
import enums;
import character;
import randomengine;

Shade::Shade(Position pos) : Player(Race::SHADE, 150, 25, 25, pos) {
}

double Shade::getScore() const {
    return std::round(totGold * 1.5); 
}

std::unique_ptr<Player> Shade::reset() const {
    return std::make_unique<Shade>(*this);
}

std::string Shade::getRaceName() const {
    return "Shade";
}

Drow::Drow(Position pos) : Player{Race::DROW, 150, 25, 15, pos} {
    currentHP = getMaxHP();
}


std::unique_ptr<Player> Drow::reset() const {
    return std::make_unique<Drow>(*this);
}

double Drow::getPotionMultiplier() const {
    return 1.5;
}

std::string Drow::getRaceName() const {
    return "Drow";
}

Vampire::Vampire(Position pos) : Player{Race::VAMPIRE, 50, 25, 25, pos} {
    currentHP = getMaxHP();
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
    if (target.getRace() == Race::DWARF) {
        loseHP(5); // Lose 5 HP if attacking a dwarf
    } else {
        gainHP(5); // Otherwise, gain 5 HP
    }
}


std::unique_ptr<Player> Vampire::reset() const{
    return std::make_unique<Vampire>(*this);
}

std::string Vampire::getRaceName() const {
    return "Vampire";
}


Goblin::Goblin(Position pos) : Player{Race::GOBLIN, 110, 15, 20, pos} {
    currentHP = getMaxHP();
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
    if (whoFrom.getRace() == Race::ORCS) {
        loseHP(static_cast<int>(std::round(damage * 1.5)));
    } else {
        loseHP(damage);
    }
}

std::unique_ptr<Player> Goblin::reset() const {
    return std::make_unique<Goblin>(*this);
}

std::string Goblin::getRaceName() const {
    return "Goblin";
}

Troll::Troll(Position pos) : Player{Race::TROLL, 120, 25, 15, pos} {
    currentHP = getMaxHP();
}

void Troll::onTurn() {
    currentHP = (currentHP + 5 <= getMaxHP())? currentHP + 5 : getMaxHP();
}

std::unique_ptr<Player> Troll::reset() const {
    return std::make_unique<Troll>(*this);
}

std::string Troll::getRaceName() const {
    return "Troll";
}
