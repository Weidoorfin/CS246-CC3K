export module entity;

import position;
import subject;

export class Entity: public Subject {
    char Symbol;
    int Colour;
  protected:
    Position Pos;
  public:
    char getSymbol() const;
    int getColour() const;
};
