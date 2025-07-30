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
  public:
    inline static bool DLC = false; // static variable to indicate if DLC is enabled
  private:
    int currFloor = 0;
    std::vector<std::unique_ptr<Floor>> floors; // owns-a
    std::unique_ptr<Player> player;
    std::unique_ptr<TextDisplay> td;


    // private methods

    // gets to next floor, get original pointer of player from Decorator
    // also resets textdisplay and put player to the new floor and set their position
    // at the new designated position
    void nextFloor();

    // Translate a string to a direction enum
    Direction getDirection(std::string s);

    // Check if the string is a valid direction
    bool isDirection(std::string s);

    // Apply effects on the enemy with item pointer *item
    // Auto detect(cast) the type of item and apply the effects accordingly
    // if nullptr, do nothing
    void applyEffects(Entity* item);
  public:

    // default constructor, initializes the game with a floor
    Game();

    // special constructor for Game, get floor directly from istream
    explicit Game(std::istream &is);

    // Asks the player to choose their Race, and initializes the player
    // return true if initialization is successful, false otherwise
    bool init();

    /*
    Run the game, loop until the game ends, receive commands
    Commands are:
    A direction (N, S, E, W, NW, NE, SW, SE) to move the player to direction
    "u" + a direction to use the item at the direction
    "a" + a direction to attack the enemy at the direction
    "f" to toggle enemy move
    "r" to restart, directly terminate
    "q" to quit the game, directly terminate
    "e" to end this round

    notice a player can maximum apply once move, once attack, and once use item in a turn
    if all avaiable actions are used, the game automatically ends the turn
    otherwise the player must end the turn by themselves
    enemymovements are done after player's turn ends

    return the game state after the game ends
    GameState::Finish if the game ends normally, either win or lose
    GameState::Restart if the player wants to restart the game
    GameState::QUIT if the player quits the game
    */
    GameState run();

    // This will only be called if the game is finished as decribed GameState::Finish
    // scinario descriped above, it will prints the score if win, otherwise prints the lose message
    void endGame(bool win) const;

    // default destructor
    ~Game() = default;
};
