module concretedecorator;

import <memory>;
import <cmath>;
import player;
import potion;
import potiondecorator;
import character;

BAEff::BAEff(std::unique_ptr<Player> wrapped) : PotionDecorator(std::move(wrapped)) {}

int BAEff::getAtk() const {
    double val = base->getAtk() + 5.0 * base->getPotionMultiplier();
    return static_cast<int>(std::round(val));
}

std::unique_ptr<Player> BAEff::applyEffect(std::unique_ptr<Player> player) {
    return std::make_unique<BAEff>(std::move(player));
}

BDEff::BDEff(std::unique_ptr<Player> wrapped) : PotionDecorator(std::move(wrapped)) {}

int BDEff::getDef() const {
    double val = base->getDef() + 5.0 * base->getPotionMultiplier();
    return static_cast<int>(std::round(val));
}

std::unique_ptr<Player> BDEff::applyEffect(std::unique_ptr<Player> player) {
    return std::make_unique<BDEff>(std::move(player));
}

WAEff::WAEff(std::unique_ptr<Player> wrapped) : PotionDecorator(std::move(wrapped)) {}

int WAEff::getAtk() const {
    double val = base->getAtk() - 5.0 * base->getPotionMultiplier();
    val = val > 0 ? val : 0;
    return static_cast<int>(std::round(val));
}

std::unique_ptr<Player> WAEff::applyEffect(std::unique_ptr<Player> player) {
    return std::make_unique<WAEff>(std::move(player));
}

WDEff::WDEff(std::unique_ptr<Player> wrapped) : PotionDecorator(std::move(wrapped)) {}

int WDEff::getDef() const {
    double val = base->getDef() - 5.0 * base->getPotionMultiplier();
    val = val > 0 ? val : 0;
    return static_cast<int>(std::round(val));
}

std::unique_ptr<Player> WDEff::applyEffect(std::unique_ptr<Player> player) {
    return std::make_unique<WDEff>(std::move(player));
}
