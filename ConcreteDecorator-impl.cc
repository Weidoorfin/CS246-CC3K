module concretedecorator;

BAEff::BAEff(std::unique_ptr<Player> wrapped) : PotionDecorator(std::move(wrapped)) {}

int BAEff::getAtk() const {
    return base->getAtk() + 5 * base->getPotionMultiplier();
}

std::unique_ptr<Player> BAEff::applyEffect(std::unique_ptr<Player> player) const {
    return std::make_unique<BAEff>(std::move(player));
}

BDEff::BDEff(std::unique_ptr<Player> wrapped) : PotionDecorator(std::move(wrapped)) {}

int BDEff::getDef() const {
    return base->getDef() + 5 * base->getPotionMultiplier();
}

std::unique_ptr<Player> BDEff::applyEffect(std::unique_ptr<Player> player) const {
    return std::make_unique<BDEff>(std::move(player));
}

WAEff::WAEff(std::unique_ptr<Player> wrapped) : PotionDecorator(std::move(wrapped)) {}

int WAEff::getAtk() const {
    int modified = base->getAtk() - 5 * base->getPotionMultiplier();
    return modified > 0 ? modified : 0;
}

std::unique_ptr<Player> WAEff::applyEffect(std::unique_ptr<Player> player) const {
    return std::make_unique<WAEff>(std::move(player));
}

WDEff::WDEff(std::unique_ptr<Player> wrapped) : PotionDecorator(std::move(wrapped)) {}

int WDEff::getDef() const {
    int modified = base->getDef() - 5 * base->getPotionMultiplier();
    return modified > 0 ? modified : 0;
}

std::unique_ptr<Player> WDEff::applyEffect(std::unique_ptr<Player> player) const {
    return std::make_unique<WDEff>(std::move(player));
}