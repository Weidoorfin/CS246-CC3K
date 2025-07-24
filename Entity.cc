export module entity;

import position;
import enums;
import abstractos;

export class Entity {
    char symbol;
    int colour;
  protected:
    Position pos;
    EntityType entity;
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
