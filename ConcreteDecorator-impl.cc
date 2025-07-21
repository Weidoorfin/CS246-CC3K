module concretedecorator;

BAEff::BAEff(std::unique_ptr<Player> wrapped) : PotionDecorator(std::move(wrapped)) {}

int BAEff::getAtk() const {
    return base->getAtk() + 5;
}
std::unique_ptr<Player> BAEff::usePotion(const Potion& potion) {
    auto wrapped = base->usePotion(potion);
    return std::make_unique<BAEff>(std::move(wrapped));
}


BDEff::BDEff(std::unique_ptr<Player> wrapped) : PotionDecorator(std::move(wrapped)) {}

int BDEff::getDef() const {
    return base->getDef() + 5;
}

std::unique_ptr<Player> BDEff::usePotion(const Potion& potion) {
    auto wrapped = base->usePotion(potion);
    return std::make_unique<BDEff>(std::move(wrapped));
}

WAEff::WAEff(std::unique_ptr<Player> wrapped) : PotionDecorator(std::move(wrapped)) {}

int WAEff::getAtk() const {
    int modified = base->getAtk() - 5;
    return modified > 0 ? modified : 0;
}

std::unique_ptr<Player> WAEff::usePotion(const Potion& potion) {
    auto wrapped = base->usePotion(potion);
    return std::make_unique<WAEff>(std::move(wrapped));
}

WDEff::WDEff(std::unique_ptr<Player> wrapped) : PotionDecorator(std::move(wrapped)) {}

int WDEff::getDef() const {
    int modified = base->getDef() - 5;
    return modified > 0 ? modified : 0;
}

std::unique_ptr<Player> WDEff::usePotion(const Potion& potion) {
    auto wrapped = base->usePotion(potion);
    return std::make_unique<WDEff>(std::move(wrapped));
}