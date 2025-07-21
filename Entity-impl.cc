module entity;

import position;

Entity::Entity(char symbol, int colour, Position pos)
    : symbol{symbol}, colour{colour}, pos{pos} {
    entity = EntityType::UNINITIALIZED; // Default to uninitialized
}
Entity::~Entity() {}
char getSymbol() const { return symbol; }
int getColour() const { return colour; }
Position getPos() const { return pos; }
