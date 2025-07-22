export module entity;

import position;
import enums;
import abstractos;

export class Entity: public Subject {
    char symbol;
    int colour;
    EntityType entity; // Type of entity 
  protected:
    // characters need to change their position
    Position pos;
  public:
    Entity(char symbol, int colour, Position pos);
    EntityType getEntityType();
    char getSymbol() const;
    int getColour() const;
    Position getPos() const;
    bool isSpace() const;
    bool isFloor() const;
    virtual ~Entity() = 0;
};
