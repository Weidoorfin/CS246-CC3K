// export module display;

// import <iostream>;
// import <vector>;

// import subject;

#infdef DISPLAY_H
#define DISPLAY_H
#include <iostream>
#include <vector>

#include "Subject.h"

export class Display: public Subject {
    Subject* entity;
    vector<vector<char>> Grid;
  public:
    void render();
    void notify();
}

#endif
