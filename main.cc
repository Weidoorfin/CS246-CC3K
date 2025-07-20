// main.cc
// This file is part of CC3K, a C++ roguelike game.

import <string>;
import <memory>;
import game;

using namespace std;

int main(int argc, char* argv[]) {
    // Initialize the game
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
    g->setDisplay();
    g->init();
    return 0;
} // main
