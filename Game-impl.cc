module game;

import <iostream>;
import <string>;
import <sstream>;
import <memory>;
import <vector>;

import enums;
import floor;
import player;
import concreteenemies;
import playerfactory;
import textdisplay;
import entity;
import treasure;
import potion;
import position;

void Game::nextFloor() {
    floors[currFloor]->setPlayer(player.get());
    td->attach(floors[currFloor].get());
    td->setLastAction("Player character has moved to the next floor.");
}

Direction Game::getDirection(std::string s) {
    if (s == "N") return Direction::N;
    else if (s == "NE") return Direction::NE;
    else if (s == "E") return Direction::E;
    else if (s == "SE") return Direction::SE;
    else if (s == "S") return Direction::S;
    else if (s == "SW") return Direction::SW;
    else if (s == "W") return Direction::W;
    else if (s == "NW") return Direction::NW;
    return Direction::N; // Default direction if input is invalid
}

bool Game::isDirection(std::string s) {
    return (s == "N" || s == "NE" || s == "E" || s == "SE" ||
            s == "S" || s == "SW" || s == "W" || s == "NW");
}

void Game::applyEffects(Entity* item) {
    if (!item) return;
    
    if (item->getEntityType() == EntityType::TREASURE) {
        auto treasure = dynamic_cast<Treasure*>(item);
        if (treasure) {
            player = treasure->applyEffect(std::move(player));
        }
    } else if (item->getEntityType() == EntityType::POTION) {
        auto potion = dynamic_cast<Potion*>(item);
        if (potion) {
            player = potion->applyEffect(std::move(player));
        }
    }
}

Game::Game() {
    for (int i = 0; i < MAXFLOOR; ++i) {
        floors.push_back(std::make_unique<Floor>());
    }
}

Game::Game(std::istream &is) {
    for (int i = 0; i < MAXFLOOR; ++i) {
        std::ostringstream oss;
        std::string line;
        for (int j = 0; j < 25; j++) {
            getline(is, line); 
            oss << line << '\n';
        }
        std::istringstream iss(oss.str());
        floors.push_back(std::make_unique<Floor>(iss));
    }
}

bool Game::init() {
    td = std::make_unique<TextDisplay>(); 
    td->intro();
    Merchant::hostile = false; // Reset merchant hostility
    while (!player) {
        using namespace std;
        cout << "Please choose your race:" << endl;
        string raceChoice;
        getline(cin, raceChoice);
        string confirmChoice;
        if (raceChoice == "Shade") {
            cout << "You have chosen Shade." << endl;
            cout << "Stats:" << endl;
            cout << "MaxHP: 125, Atk: 25, Def: 25" << endl;
            cout << "Ability: Maginify the score by 1.5x at end of game." << endl;
            cout << "Please confirm your choice by input y" << endl;
            getline(cin, confirmChoice);
            if (confirmChoice == "y") {
                player = PlayerFactory::createPlayer(Race::SHADE, Position{0, 0});
            }
        } else if (raceChoice == "Drow") {
            cout << "You have chosen Drow." << endl;
            cout << "Stats:" << endl;
            cout << "MaxHP: 150, Atk: 25, Def: 15" << endl;
            cout << "Ability: All potion effects are magnified with 1.5x" << endl;
            cout << "Please confirm your choice by input y" << endl;
            getline(cin, confirmChoice);
            if (confirmChoice == "y") {
                player = PlayerFactory::createPlayer(Race::DROW, Position{0, 0});
            }
        } else if (raceChoice == "Vampire") {
            cout << "You have chosen Vampire." << endl;
            cout << "Stats:" << endl;
            cout << "StartHP: 50, Atk: 25, Def: 25" << endl;
            cout << "Ability: Gain 5 HP every successful attack, MaxHP not capped." << endl;
            cout << "Please confirm your choice by input y" << endl;
            getline(cin, confirmChoice);
            if (confirmChoice == "y") {
                player = PlayerFactory::createPlayer(Race::VAMPIRE, Position{0, 0});
            }
        } else if (raceChoice == "Troll") {
            cout << "You have chosen Troll." << endl;
            cout << "Stats:" << endl;
            cout << "MaxHP: 120, Atk: 25, Def: 15" << endl;
            cout << "Ability: Regenerate 5 HP every turn, capped at MaxHP." << endl;
            cout << "Please confirm your choice by input y" << endl;
            getline(cin, confirmChoice);
            if (confirmChoice == "y") {
                player = PlayerFactory::createPlayer(Race::TROLL, Position{0, 0});
            }
        } else if (raceChoice == "Goblin") {
            cout << "You have chosen Goblin." << endl;
            cout << "Stats:" << endl;
            cout << "MaxHP: 110, Atk: 15, Def: 20" << endl;
            cout << "Ability: Steal 5 gold every successful slain" << endl;
            cout << "Please confirm your choice by input y" << endl;
            getline(cin, confirmChoice);
            if (confirmChoice == "y") {
                player = PlayerFactory::createPlayer(Race::GOBLIN, Position{0, 0});
            }
        } else if (raceChoice == "q") {
            cout << "Quitting the game." << endl;
            return false; // Exit the game
        } else {
            cout << "Invalid choice. Please choose a valid race." << endl;
        }
    }
    // Initialize the display grid or any other setup needed
    // TODO: read in first floor from emptyfloor.txt
    td->attach(floors[0].get());
    td->setLastAction("Player character has spawned.");
    return true; // Initialization successful
}

GameState Game::run() {
    floors[currFloor]->setPlayer(player.get());
    while (player->isAlive()) {
        // Game loop will keep running until the player dies
        // Check if player has reached stairs or performs any action.
        if (floors[currFloor]->isComplete()) {
            currFloor++;
            if (currFloor < MAXFLOOR) {
                nextFloor();
            } else {
                endGame(true); // Player has completed all floors
                return GameState::Finish; // Player has completed all floors
            }
        }
        // Reset enemy move toggles for new turn
        floors[currFloor]->resetAllEnemyMoveToggle();
        auto item = floors[currFloor]->getItemAt(player->getPos());
        applyEffects(item);
        
        td->showGameUI();
        std::string cmd;
        std::vector<bool> validCommands(3, true);
        bool finish = false;
        while (!finish) {
            std::cout << "Enter command (input e to finish this round): " << std::endl;
            getline(std::cin, cmd);
            std::istringstream iss{cmd};
            std::string command;
            if (iss.eof()) return GameState::Quit;
            iss >> command;
            if (isDirection(command)) {
                if (!validCommands[0]) {
                    td->showGameUI();
                    std::cout << "You have performed this action already." << std::endl;
                    continue;
                }
                auto dir = getDirection(command);
                auto [moved, item] = floors[currFloor]->playerMove(dir);
                if (!moved) {
                    td->showGameUI();
                    std::cout << "Invalid place to move!" << std::endl;
                    continue;
                }
                applyEffects(item);
                validCommands[0] = false; // Mark the command as used
                td->setLastAction("Player character has moved to direction: " + command + ".");
            } else if (command == "a") {
                iss >> command; // Get the target direction for attack
                if (!validCommands[1]) {
                    td->showGameUI();
                    std::cout << "You have performed this action already." << std::endl;
                    continue;
                }
                if (isDirection(command)) {
                    auto dir = getDirection(command);
                    if (!floors[currFloor]->playerAttack(dir)) {
                        td->showGameUI();
                        std::cout << "No enemy to attack!" << std::endl;
                        continue;
                    }
                } else {
                    td->showGameUI();
                    std::cout << "Invalid direction for attack." << std::endl;
                    continue;
                }
                validCommands[1] = false; // Mark the command as used
                td->setLastAction("Player character has attacked in direction " + command + ".");
            } else if (command == "u") {
                if (!validCommands[2]) {
                    td->showGameUI();
                    std::cout << "You have performed this action already." << std::endl;
                    continue;
                }
                iss >> command; // Get the target direction for use item
                if (isDirection(command)) {
                    auto dir = getDirection(command);
                    auto [used, item] = floors[currFloor]->playerUseItem(dir);
                    if (!used) {
                        td->showGameUI();
                        std::cout << "No item to use!" << std::endl;
                        continue;
                    }
                    applyEffects(item);
                } else {
                    td->showGameUI();
                    std::cout << "Invalid direction for use item." << std::endl;
                    continue;
                }
                validCommands[2] = false; // Mark the command as used
                td->setLastAction("Player character has used an item in direction " + command + ".");
            } else if (command == "q") {
                return GameState::Quit; // Quit the game
            } else if (command == "f") {
                td->setLastAction("Enemy movement has been toggled.");
                floors[currFloor]->toggleAllEnemyMovement();
            } else if (command == "r") {
                return GameState::Restart; // Restart the game
            } else if (command == "e") {
                break;
            } else {
                std::cout << "Invalid command. Please try again." << std::endl;
            }
            finish = true;
            for (auto p : validCommands) {
                if (p) {
                    finish = false;
                    break;
                }
            }
            td->showGameUI();
        }
        // Auto Enemy move
        floors[currFloor]->enemyTurn(); // Handle enemy actions
        td->setLastAction("Enemy turn finished.");
    } // while (player->isAlive())
    endGame(false);
    return GameState::Finish; // Player has died, end the game
}

void Game::endGame(bool win) const {
    using namespace std;
    if (win) {
        cout << "Congratulations! You have completed all floors!" << endl;
        cout << "Your final score is: " << player->getScore() << endl;
    } else {
        cout << "Game Over! You have died." << endl;
    }
}
