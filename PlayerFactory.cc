export module playerfactory;

import player;
import enums;

export class PlayerFactory {
public:
    static std::unique_ptr<Player> createPlayer(PlayerRace race);
};
