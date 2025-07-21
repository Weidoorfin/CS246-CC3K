// main.cc
// This file is part of CC3K, a C++ roguelike game.

import <iostream>;
import <memory>;
import game;

using namespace std;

int main(int argc, char* argv[]) {
    bool playAgain = true;
    while (playAgain) {
        unique_ptr<Game> g;
        if (argc == 3) {
            ifstream inFile{argv[1]};
            g = make_unique<Game>(inFile, stoi(argv[2]));
        } else if (argc == 2) {
            ifstream inFile{argv[1]};
            g = make_unique<Game>(inFile);
        } else {
            g = make_unique<Game>();
        }
        if (!g->init()) {
            break; // If initialization fails, exit the loop
        }
        if (g->run()) {
            // If the game is over, ask if the player wants to play again
            char choice;
            cout << "Do you want to play again? (y/n): ";
            cin >> choice;
            playAgain = (choice == 'y');
        }
        else {
            playAgain = false;
        }
        cout << "Game Over! Thanks for playing!" << endl;
    }
    return 0;
} // main
