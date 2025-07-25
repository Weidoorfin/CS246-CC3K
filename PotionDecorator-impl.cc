module potiondecorator;

import <memory>;
import player;
import character;
import enums;

PotionDecorator::PotionDecorator(std::unique_ptr<Player> wrapped)
  : Player{
      wrapped->getRace(),
      wrapped->getMaxHP(),
      wrapped->getAtk(),
      wrapped->getDef(),
      wrapped->getSymbol(),
      wrapped->getColour(),
      wrapped->getPos()
    }, base{std::move(wrapped)}
{}

Race PotionDecorator::getRace() const { return base->getRace(); }
int PotionDecorator::getAtk() const { return base->getAtk(); }
int PotionDecorator::getDef() const { return base->getDef(); }
int PotionDecorator::getGold() const { return base->getGold(); }
void PotionDecorator::gainGold(int amount) { return base->gainGold(amount); }
int PotionDecorator::getMaxHP() const { return base->getMaxHP(); }

double PotionDecorator::getScore() const { return base->getScore(); }
void PotionDecorator::onTurn() { base->onTurn(); }
void PotionDecorator::attack(Character &target) { base->attack(target); }
void PotionDecorator::onHit(Character &whoFrom) { base->onHit(whoFrom); }

void PotionDecorator::gainHP(int inc) { base->gainHP(inc); }
void PotionDecorator::loseHP(int dec) { base->loseHP(dec); }
double PotionDecorator::getPotionMultiplier() const {
    return base->getPotionMultiplier();
}
std::string PotionDecorator::getRaceName() const {
    return base->getRaceName();
}

int PotionDecorator::getCurrentHP() const {
    return base->getCurrentHP();
}

std::unique_ptr<Player> PotionDecorator::reset() const {
    return base->reset();
}

std::unique_ptr<Player> PotionDecorator::applyEffect(std::unique_ptr<Player> player) {
    return std::make_unique<PotionDecorator>(std::move(player));
}
