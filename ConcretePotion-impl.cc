module concretepotion;

import <memory>;
import potion;
import enums;
import position;
import player;

RH::RH(Position pos) : Potion(PotionType::RH, pos) {}

std::unique_ptr<Player> RH::applyEffect(std::unique_ptr<Player> player) const {
    int healAmount = 10;
    healAmount = healAmount * player->getPotionMultiplier();
    player->gainHP(healAmount);
    return player;
}


PH::PH(Position pos) : Potion(PotionType::PH, pos) {}

std::unique_ptr<Player> PH::applyEffect(std::unique_ptr<Player> player) const {
    int amount = 10;
    amount = amount * player->getPotionMultiplier();
    player->loseHP(amount);
    return player;
}

BA::BA(Position pos) : Potion(PotionType::BA, pos) {}

std::unique_ptr<Player> BA::applyEffect(std::unique_ptr<Player> player) const {
    return std::make_unique<BAEff>(std::move(player));
}

BD::BD(Position pos) : Potion(PotionType::BD, pos) {}

std::unique_ptr<Player> BD::applyEffect(std::unique_ptr<Player> player) const {
    return std::make_unique<BDEff>(std::move(player));
}

WA::WA(Position pos) : Potion(PotionType::WA, pos) {}

std::unique_ptr<Player> WA::applyEffect(std::unique_ptr<Player> player) const {
    return std::make_unique<WAEff>(std::move(player));
}

WD::WD(Position pos) : Potion(PotionType::WD, pos) {}

std::unique_ptr<Player> WD::applyEffect(std::unique_ptr<Player> player) const {
    return std::make_unique<WDEff>(std::move(player));
}