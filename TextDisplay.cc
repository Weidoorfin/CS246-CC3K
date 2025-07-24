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
    void attach(const Floor* f);
    void setLastAction(const std::string& action);
    void intro() const;
    void showGameUI() const;
  private:
    std::string getColourCode(int colour) const;
};
