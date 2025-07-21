export module entity;

import position;
import enums;
import abstractos;

export class Entity: public Subject {
    char symbol;
    int colour;
    EntityType entity; // Type of entity (e.g., PLAYER, ENEMY, POTION, TREASURE)
  protected:
    // characters need to change their position
    Position pos;
  public:
    Entity(char symbol, int colour, Position pos);
    char getSymbol() const;
    int getColour() const;
    Position getPos() const;
    virtual ~Entity() = 0;
};
