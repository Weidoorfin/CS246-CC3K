module textdisplay;

import <iostream>;
import <string>;
import <memory>;
import <vector>;
import chamber;
import player;
import floor;


void TextDisplay::attach(const Floor* f) {
    floor = f;
}

void TextDisplay::setLastAction(const std::string& action) {
    lastAction = action;
}

void TextDisplay::intro() const {
    using namespace std;
    cout << "Welcome to CC3K! Prepare for your adventure." << endl;
    cout << "Start the game by choosing your race:" << endl;
    cout << "Shade" << endl;
    cout << "Drow" << endl;
    cout << "Vampire" << endl;
    cout << "Troll" << endl;
    cout << "Goblin" << endl;
    cout << "Input the your choice by entering the race name." << endl;
    cout << "type \"q\" anytime to quit the game." << endl;
    cout << "Race description will be shown after your choice." << endl;
    return;
}

void TextDisplay::showGameUI() const {
    using namespace std;
    const auto& grid = floor->getGrid();
    const auto& terrain = floor->getTerrain();
    int height = grid.size();
    int width = grid[0].size();



    for (int y = 0; y < height; ++y) {
        for (int x = 0; x < width; ++x) {
            if (grid[y][x] == nullptr) {
                cout << getColourCode(terrain[y][x]->getColour());
                cout << terrain[y][x]->getSymbol();
                cout << "\033[0m";
            } else {
                cout << getColourCode(grid[y][x]->getColour());
                cout << grid[y][x]->getSymbol();
                cout << "\033[0m";
            }
        }
        cout << endl;
    }
    auto player = floor->getPlayer();
    cout << "Race: " << player->getRaceName();
    cout << " Gold: " << player->getGold() << endl;
    cout << "HP: " << player->getCurrentHP() << endl;
    cout << "Atk: " << player->getAtk() << endl;
    cout << "Def: " << player->getDef() << endl;
    cout << "Action: " << lastAction << endl;
}

std::string TextDisplay::getColourCode(int colour) const {
    switch (colour) {
        case 21: return "\033[1;33m"; // Yellow
        case 124: return "\033[1;31m"; // Red
        case 184: return "\033[1;32m"; // Green
        case 40: return "\033[1;34m"; // Blue
        default: return "\033[0m"; // Reset
    }
}
