export module playerfactory;

import <memory>;
import player;
import concreteplayer;
import enums;
import position;

export class PlayerFactory {
public:
    static std::unique_ptr<Player> createPlayer(Race race, Position pos);
};
