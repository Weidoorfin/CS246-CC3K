export module display;

import <iostream>;
import <vector>;

import subject;

export class Display: public Subject {
    Subject* entity;
    vector<vector<char>> Grid;
  public:
    void render();
    void notify();
}
