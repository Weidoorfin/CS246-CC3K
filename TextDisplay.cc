export module TextDisplay;

import <iostream>;
import <vector>;

import abstractos;
import enums;

export class TextDisplay {
    const Floor* floor;
    std::string lastAction;
  public:
    void attach(const Floor* f);
    void setLastAction(const std::string& action);
    void intro() const;
    void showGameUI() const;
}
