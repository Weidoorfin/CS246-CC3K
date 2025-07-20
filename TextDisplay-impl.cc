module textdisplay;

import <iostream>;
import <memory>;
import <vector>;
import chamber;
import player;

class TextDisplay {
  std::vector<std::shared_ptr<Chamber>> chambers;
  std::shared_ptr<Player> player;
public:
  void attach(std::shared_ptr<Chamber> chamber);
  void update();
};
void TextDisplay::attach(std::shared_ptr<Chamber> chamber) {
    chambers.push_back(chamber);
}

void TextDisplay::intro() {
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
