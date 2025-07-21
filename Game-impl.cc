module game;

import <iostream>;
import <memory>;

import enums;
import floor;
import player;
import textdisplay;

Game::Game(std::istream &is) {
    for (int i = 0; i < MAXFLOOR; ++i) {
        floors.push_back(std::make_unique<Floor>(is));
    }
}

Game::Game(const std::string &filename, int seed) {
    for (int i = 0; i < MAXFLOOR; ++i) {
        floors.push_back(std::make_unique<Floor>(is));
    }
}

bool Game::init() {
    currFloor = 1;
    PlayerRace Race;
    td = std::make_unique<TextDisplay>(); 
    td->intro();
    while (!player) {
        using namespace std;
        cout << "Please choose your race:" << endl;
        string raceChoice;
        cin >> raceChoice;
        char confirmChoice;
        switch(raceChoice) {
            case "Shade":
                cout << "You have chosen Shade." << endl;
                cout << "Stats:" << endl;
                cout << "MaxHP: 125, Atk: 25, Def: 25" << endl;
                cout << "Ability: Maginify the score by 1.5x at end of game." << endl;
                cout << "Please confirm your choice by input y" << endl;
                cin >> confirmChoice;
                if (confirmChoice == 'y') {
                    player = std::make_shared<Player>(PlayerRace::Shade);
                }
                break;
            case "Drow":
                cout << "You have chosen Drow." << endl;
                cout << "Stats:" << endl;
                cout << "MaxHP: 150, Atk: 25, Def: 15" << endl;
                cout << "Ability: All potion effects are magnified with 1.5x" << endl;
                cout << "Please confirm your choice by input y" << endl;
                cin >> confirmChoice;
                if (confirmChoice == 'y') {
                    player = std::make_shared<Player>(PlayerRace::Drow);
                }
                break;
            case "Vampire":
                cout << "You have chosen Vampire." << endl;
                cout << "Stats:" << endl;
                cout << "StartHP: 50, Atk: 25, Def: 25" << endl;
                cout << "Ability: Gain 5 HP every successful attack, MaxHP not capped." << endl;
                cout << "Please confirm your choice by input y" << endl;
                cin >> confirmChoice;
                if (confirmChoice == 'y') {
                    player = std::make_shared<Player>(PlayerRace::Vampire);
                }
                break;
            case "Troll":
                cout << "You have chosen Troll." << endl;
                cout << "Stats:" << endl;
                cout << "MaxHP: 120, Atk: 25, Def: 15" << endl;
                cout << "Ability: Regenerate 5 HP every turn, capped at MaxHP." << endl;
                cout << "Please confirm your choice by input y" << endl;
                cin >> confirmChoice;
                if (confirmChoice == 'y') {
                    player = std::make_shared<Player>(PlayerRace::Troll);
                }
                break;
            case "Goblin":
                cout << "You have chosen Goblin." << endl;
                cout << "Stats:" << endl;
                cout << "MaxHP: 110, Atk: 15, Def: 20" << endl;
                cout << "Ability: Steal 5 gold every successful slain" << endl;
                cout << "Please confirm your choice by input y" << endl;
                cin >> confirmChoice;
                if (confirmChoice == 'y') {
                    player = std::make_shared<Player>(PlayerRace::Goblin);
                }
                break;
            case "q":
                cout << "Quitting the game." << endl;
                return; // Exit the game
            default:
                cout << "Invalid choice. Please choose a valid race." << endl;
                break; // Continue
        }
    }
    // Initialize the display grid or any other setup needed
    // TODO: read in first floor from emptyfloor.txt
    player = std::make_unique<Player>(Race);
}

void Game::run() {
    while (player->isAlive()) {  
        // Game loop will keep running until the player dies
        // Check if player has reached stairs or performs any action.
        if (floor->isComplete()) {
            if (currFloor < MAXFLOOR)
            ++currFloor;
            // replace current floor with new floor
            floor = make_unique<Floor>();
            // TODO: read in current floor from emptyfloor.txt
            floor->attach(td);
            floor->init(); 
        }
    }
    endGame();
}

void Game::endGame() {
    std::cout << "Game Over! Player has died.\n";
    // Clean up the game. Game is ready to be initialized again for reuse
    // TODO:
}
