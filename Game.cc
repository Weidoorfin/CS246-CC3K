export module game;

// import syslibs here
import <vector>;
import <memory>;
// import module here
import floor;
import player;
import enums;
import textdisplay;

const int MAXFLOOR = 5;

export class Game {
    int currFloor = 0;
    vector<unique_ptr<Floor>> floors; // owns-a
    unique_ptr<Player> player;
    unique_ptr<TextDisplay> td;

    void nextFloor();
    Direction getDirection(string s);
    bool isDirection(string s);
  public:
    Game();
    Game(std::istream &is); // constructor with input stream, reading the floor from file
    Game(std::istream &is, int seed);
    bool init(); // initializing the game
    GameState run();
    void endGame() const; // end the game, return true if win, false if lose
    ~Game() = default; // default destructor, only used when main() is terminated
};

