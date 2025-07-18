export module game;

// import syslibs here
import <vector>;
// import module here
import observer;
import player;
import enums;

export class Game: public Subject {
    int currFloor;
    vector<Floor> floor(5);
    Player player;

  public:
    void run(PlayerRace race);
    void nextFloor();
};

