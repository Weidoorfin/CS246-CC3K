// export module entity;

// import position;
// import subject;

#ifndef ENTITY_H
#define ENTITY_H

#include "Position.h"
#include "Subject.h"

export class Entity: public Subject {
    char Symbol;
    int Colour;
  protected:
    Position Pos;
  public:
    char getSymbol() const;
    int getColour() const;
};

#endif

