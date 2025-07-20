export module TextDisplay;

import <iostream>;
import <vector>;

import subject;
import enums;

export class Display: public Observer {
    Subject* entity;
    std::vector<std::vector<char>> grid;
  public:
    void render();
    void notify();
    void intro();
}
