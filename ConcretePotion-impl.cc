module concretepotion;

import <memory>;
import <cmath>;
import potion;
import enums;
import position;
import player;
import concretedecorator;

RH::RH(Position pos) : Potion(PotionType::RH, pos) {}

std::unique_ptr<Player> RH::applyEffect(std::unique_ptr<Player> player) {
    double healAmount = 10.0;
    healAmount = healAmount * player->getPotionMultiplier();
    player->gainHP(static_cast<int>(std::round(healAmount)));
    return player;
}


PH::PH(Position pos) : Potion(PotionType::PH, pos) {}

std::unique_ptr<Player> PH::applyEffect(std::unique_ptr<Player> player) {
    double amount = 10.0;
    amount = amount * player->getPotionMultiplier();
    player->loseHP(static_cast<int>(std::round(amount)));
    return player;
}

BA::BA(Position pos) : Potion(PotionType::BA, pos) {}

std::unique_ptr<Player> BA::applyEffect(std::unique_ptr<Player> player) {
    return std::make_unique<BAEff>(std::move(player));
}

BD::BD(Position pos) : Potion(PotionType::BD, pos) {}

std::unique_ptr<Player> BD::applyEffect(std::unique_ptr<Player> player) {
    return std::make_unique<BDEff>(std::move(player));
}

WA::WA(Position pos) : Potion(PotionType::WA, pos) {}

std::unique_ptr<Player> WA::applyEffect(std::unique_ptr<Player> player) {
    return std::make_unique<WAEff>(std::move(player));
}

WD::WD(Position pos) : Potion(PotionType::WD, pos) {}

std::unique_ptr<Player> WD::applyEffect(std::unique_ptr<Player> player) {
    return std::make_unique<WDEff>(std::move(player));
}