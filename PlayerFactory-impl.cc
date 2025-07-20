module playerfactory;

static std::unique_ptr<Player> PlayerFactory::createPlayer(PlayerRace race) {
    switch(race) {
        case PlayerRace::SHADE:
            return std::make_unique<Shade>();
        case PlayerRace::DROW:
            return std::make_unique<Drow>();
        case PlayerRace::VAMPIRE:
            return std::make_unique<Vampire>();
        case PlayerRace::TROLL:
            return std::make_unique<Troll>();
        case PlayerRace::GOBLIN:
            return std::make_unique<Goblin>();
    }
}
