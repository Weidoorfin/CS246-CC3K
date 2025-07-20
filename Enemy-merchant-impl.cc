module merchant;

import enemy;
import chamber;
import enums;

Merchant::Merchant(Player &player, Chamber &chamber)
    : Enemy{EnemyType::MERCHANT, player, chamber, 30, 70, 5} {}

Merchant::~Merchant() {}

void Merchant::onHit(Character &whoFrom) {
    // Implement the logic for handling a hit from another character
    int damage = ceil((100 / (100 + getDef())) * whoFrom.getAtk());
    if (damage < currentHP) {
        currentHP -= damage;
    } else {
        currentHP = 0; // Character dies
    }
    hostile = true; // Merchant becomes hostile after being hit
    notifyObservers();
}