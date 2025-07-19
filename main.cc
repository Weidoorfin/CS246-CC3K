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
    Game g;
    g.setDisplay();
    g.run();
    return 0;
} // main
