export module TextDisplay;

import <iostream>;
import <vector>;
import subject;

export class Display: public Observer {
    Subject* entity;
    std::vector<std::vector<char>> grid;
  public:
    void render();
    void notify();
}
