module concretepotion;

// Permanent effects: directly modify HP, return same player
std::unique_ptr<Player> RH::applyEffect(std::unique_ptr<Player> player) const {
    player->gainHP(10);
    return player;
}

std::unique_ptr<Player> PH::applyEffect(std::unique_ptr<Player> player) const {
    player->loseHP(10);
    return player;
}

// Temporary effects: wrap player in decorator
std::unique_ptr<Player> BA::applyEffect(std::unique_ptr<Player> player) const {
    return std::make_unique<BAEff>(std::move(player));
}

std::unique_ptr<Player> BD::applyEffect(std::unique_ptr<Player> player) const {
    return std::make_unique<BDEff>(std::move(player));
}

std::unique_ptr<Player> WA::applyEffect(std::unique_ptr<Player> player) const {
    return std::make_unique<WAEff>(std::move(player));
}

std::unique_ptr<Player> WD::applyEffect(std::unique_ptr<Player> player) const {
    return std::make_unique<WDEff>(std::move(player));
}