export module entity;

import position;
import subject;

export class Entity: public Subject {
    char symbol;
    int colour;
  protected:
    // characters need to change their posiiton
    Position pos;
  public:
    char getSymbol() const;
    int getColour() const;
    Position getPos() const;
    virtual ~Entity() = 0;
};
