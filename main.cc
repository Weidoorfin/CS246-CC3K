// main.cc
// This file is part of CC3K, a C++ roguelike game.

import <iostream>;
import <fstream>;
import <memory>;

import game;
import randomengine;
import enums;
import floor;

using namespace std;

int main(int argc, char* argv[]) {
    bool playAgain = true;
    string dlc;
    cout << "Do you want to enable DLC content? (Input 'DLC' to enable, any other input will disable): ";
    cout << "You Must do it here before starting the game." << endl;
    getline(cin, dlc);
    if (dlc == "DLC") {
        Game::DLC = true; // Enable DLC content if the user inputs "DLC"
    } else {
        Game::DLC = false; // Default to false if any other input
    }
    while (playAgain) {
        unique_ptr<Game> g;
        if (argc == 3) {
            ifstream inFile{argv[1]};
            RandomEngine rng;
            rng.setSeed(stoi(argv[2]));
            g = make_unique<Game>(inFile);
        } else if (argc == 2) {
            ifstream inFile{argv[1]};
            g = make_unique<Game>(inFile);
        } else {
            g = make_unique<Game>();
        }
        if (!g->init()) {
            break; // If initialization fails, exit the loop
        }
        auto state = g->run();
        if (state == GameState::Finish) {
            // If the game is over, ask if the player wants to play again
            char choice;
            cout << "Do you want to play again? (y/n): ";
            cin >> choice;
            playAgain = (choice == 'y');
        } else if (state == GameState::Restart) {
            continue;
        } else if (state == GameState::Quit) {
            // If the game is quit, exit the loop
            playAgain = false;
        }
        cout << "Game Over! Thanks for playing!" << endl;
    }
    return 0;
} // main
