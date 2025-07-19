// export module game;

// // import syslibs here
// import <vector>;
// import <memory>;
// // import module here
// import floor;
// import player;
// import enums;

#ifndef GAME_H
#define GAME_H

#include <vector>
#include <memory>

#include "Floor.h"
#include "Player.h"
#include "Enums.h"

export class Game{
    int currFloor;
    unique_ptr<Floor> floor;
    unique_ptr<Player> player;

  public:
    void run(PlayerRace race);
    void nextFloor();
};

#endif
