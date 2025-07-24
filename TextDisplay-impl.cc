module textdisplay;

import <iostream>;
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
                cout << terrain[y][x]->getSymbol();
            } else {
                cout << grid[y][x]->getSymbol();
            }
        }
        cout << endl;
    }
    auto player = floor->getPlayer();
    cout << "Race: " << player->getRaceName();
    cout << "Gold: " << player->getGold() << endl;
    cout << "HP: " << player->getCurrentHP() << endl;
    cout << "Atk: " << player->getAtk() << endl;
    cout << "Def: " << player->getDef() << endl;
    cout << "Action: " << lastAction << endl;
}

