export module entity;

import position;
import subject;

export class Entity: public Subject {
    char Symbol;
    int Colour;
  protected:
    // characters need to change their posiiton
    Position Pos;
  public:
    char getSymbol() const;
    int getColour() const;
    virtual ~Entity() = 0;
};
