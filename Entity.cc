export module entity;

import position;
import abstractos;

export class Entity: public Subject {
    char symbol;
    int colour;
  protected:
    // characters need to change their position
    Position pos;
  public:
    char getSymbol() const;
    int getColour() const;
    Position getPos() const;
    virtual ~Entity() = 0;
};
