module concretepotion;

std::unique_ptr<Player> RH::usePotion(std::unique_ptr<Player> player) const {
    player->gainHP(10);
    return player;
}

std::unique_ptr<Player> PH::usePotion(std::unique_ptr<Player> player) const {
    player->loseHP(10);
    return player;
}


std::unique_ptr<Player> BA::usePotion(std::unique_ptr<Player> player) const {
    return std::make_unique<BAEff>(std::move(player));
}

std::unique_ptr<Player> BD::usePotion(std::unique_ptr<Player> player) const {
    return std::make_unique<BDEff>(std::move(player));
}

std::unique_ptr<Player> WA::usePotion(std::unique_ptr<Player> player) const {
    return std::make_unique<WAEff>(std::move(player));
}

std::unique_ptr<Player> WD::usePotion(std::unique_ptr<Player> player) const {
    return std::make_unique<WDEff>(std::move(player));
}