export module TextDisplay;

import <iostream>;
import <vector>;

import abstractos;
import enums;

export class Display: public Observer {
    Subject* floor;
    std::vector<std::vector<char>> grid;
  public:
    Display() = default; // Default constructor
    Display(Subject* floor);
    void render();
    void notify();
    void intro();
}
