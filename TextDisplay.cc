export module textdisplay;

import <iostream>;
import <string>;
import <vector>;

import abstractos;
import enums;
import floor;

export class TextDisplay {
    const Floor* floor;
    std::string lastAction;
  public:

    // set the floor pointer to the current floor
    void attach(const Floor* f);

    // set last action message
    void setLastAction(const std::string& action);

    // prints the intro when selecting race, only output
    void intro() const;

    // prints the current floor graph, and also player stats and last action
    void showGameUI() const;
  private:

    // get specific colour code for the given colour
    std::string getColourCode(int colour) const;
};
