// main.cc
// This file is part of CC3K, a C++ roguelike game.

import <fstream>;
import game;
import display;

using namespace std;

int main(int argc, char* argv[]) {
    // Initialize the game
    if (argc > 1) {
        ifstream inFile{argv[1]};
        Game g(inFile);
    }
    else {
        Game g();
    }
    g.setDisplay();
    g.init();
    return 0;
} // main
