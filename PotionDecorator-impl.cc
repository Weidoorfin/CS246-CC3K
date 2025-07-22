module potiondecorator;

import <memory>;
import player;
import character;
import item;

PotionDecorator::PotionDecorator(std::unique_ptr<Player> wrapped) : 
    Player{wrapped->getRace()}, base{std::move(wrapped)} {}

PlayerRace PotionDecorator::getRace() const { return base->getRace(); }
int PotionDecorator::getAtk() const { return base->getAtk(); }
int PotionDecorator::getDef() const { return base->getDef(); }
int PotionDecorator::getGold() const { return base->getGold(); }
int PotionDecorator::gainGold(int amount) { return base->gainGold(inc); }
int PotionDecorator::getMaxHP() const { return base->getMaxHP(); }
int PotionDecorator::getHP() const { return base->getHP(); } 

double PotionDecorator::getScore() const { return base->getScore(); }
void PotionDecorator::onTurn() { base->onTurn(); }
void PotionDecorator::useItem(Item &item) { base->useItem(item); }
void PotionDecorator::attack(Character &target) { base->attack(target); }
void PotionDecorator::onHit(Character &whoFrom) { base->onHit(whoFrom); }

void PotionDecorator::gainHP(int inc) { base->gainHP(inc); }
void PotionDecorator::loseHP(int dec) { base->loseHP(dec); }
double PotionDecorator::getPotionMultiplier() const {
    return base->getPotionMultiplier();
}

std::unique_ptr<Player> PotionDecorator::reset() {
    return base->reset();
}

std::unique_ptr<Player> PotionDecorator::applyEffect(std::unique_ptr<Player> player) const {
    return std::make_unique<PotionDecorator>(std::move(player));
}