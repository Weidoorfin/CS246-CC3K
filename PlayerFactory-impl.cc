module factory;

static std::unique_ptr<Player> PlayerFactory::createPlayer(Race race, Position pos) {
    switch(race) {
        case Race::SHADE:
            return std::make_unique<Shade>(pos);
        case Race::DROW:
            return std::make_unique<Drow>(pos);
        case Race::VAMPIRE:
            return std::make_unique<Vampire>(pos);
        case Race::TROLL:
            return std::make_unique<Troll>(pos);
        case Race::GOBLIN:
            return std::make_unique<Goblin>(pos);
    }
}
