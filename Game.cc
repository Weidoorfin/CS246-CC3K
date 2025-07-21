export module game;

// import syslibs here
import <vector>;
import <memory>;
// import module here
import floor;
import player;
import enums;

const int MAXFLOOR = 5;

export class Game {
    int currFloor;
    vector<unique_ptr<Floor>> floors; // owns-a
    unique_ptr<Player> player;
    unique_ptr<TextDisplay> td;
  public:
    Game() = default; // default constructor, creating the default game object
    Game(std::istream &is); // constructor with input stream, reading the floor from file
    Game(const std::string &filename, int seed);
    void init(); // initializing the game
    void run();
    void setDisplay();
    void nextFloor();
    void endGame();
    ~Game() = default; // default destructor, only used when main() is terminated
};

