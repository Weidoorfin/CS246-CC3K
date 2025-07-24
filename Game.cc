export module game;

// import syslibs here
import <vector>;
import <memory>;
import <string>;
// import module here
import floor;
import player;
import enums;
import textdisplay;
import entity;
import treasure;
import potion;

const int MAXFLOOR = 5;

export class Game {
    int currFloor = 0;
    std::vector<std::unique_ptr<Floor>> floors; // owns-a
    std::unique_ptr<Player> player;
    std::unique_ptr<TextDisplay> td;

    void nextFloor();
    Direction getDirection(std::string s);
    bool isDirection(std::string s);
    void applyEffects(Entity* item); // 添加这个方法
  public:
    Game();
    explicit Game(std::istream &is); // constructor with input stream, reading the floor from file
    bool init(); // initializing the game
    GameState run();
    void endGame(bool win) const; // end the game, return true if win, false if lose
    ~Game() = default; // default destructor, only used when main() is terminated
};

