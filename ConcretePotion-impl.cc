module concretepotion;

std::unique_ptr<Player> RH::usePotion(std::unique_ptr<Player> player) const {
    player->gainHP(10);
    return player;
}

std::unique_ptr<Player> PH::usePotion(std::unique_ptr<Player> player) const {
    player->loseHP(10);
    return player;
}



export class BA: public potion {
public:
    std::unique_ptr<Player> usePotion(std::unique_ptr<Player> player) const override;

};

export class BD: public potion {
public:
    std::unique_ptr<Player> usePotion(std::unique_ptr<Player> player) const override;

};

export class WA: public potion {
public:
    std::unique_ptr<Player> usePotion(std::unique_ptr<Player> player) const override;

};

export class WD: public potion {
public:
    std::unique_ptr<Player> usePotion(std::unique_ptr<Player> player) const override;

};