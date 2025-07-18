// syslibs
import <iostream>;
import <string>;
// modules
import game;
import playerfactory;
import display;
import enums;

using namespace std;

int main() {
    Display display;
    Game game;
    PlayerRace Race;

    while(true) {
        display.init();
        game.init();
        cout << "Chamber Crawler 3000 (CC3K)!" << endl;
        cout << "Please select your Race to start" << endl;
        // ... further complete
        string choice;
        cin >> choice;
    }

    return 0;
} // main
