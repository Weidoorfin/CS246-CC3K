export module entity;

import position;
import enums;
import abstractos;

// Abstract entity class, record symbol, colour, and position for all derived classes
// All Characters, Items, Enemies, Potions, Treasures are Entity
export class Entity {
    char symbol;
    int colour;
  protected:
    Position pos;
    EntityType entity;
  public:
    // Construct an entity
    Entity(char symbol, int colour, Position pos);
    virtual ~Entity() = 0;
    // Return the EntityType for entity
    EntityType getEntityType();
    // Return the symbol
    char getSymbol() const;
    // Return the color code for entity
    int getColour() const;
    // Return the Position for entity
    Position getPos() const;
    // Return true if entity has symbol of '.' '#' '+' '/' 'G' (player can move over it)
    bool isSpace() const;
    // Return true if entity has symbol of '.'
    bool isFloor() const;
    // Reset the position of the entity to p
    void setPos(Position p);
};
