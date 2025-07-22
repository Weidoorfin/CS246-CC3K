module entity;

import position;

Entity::Entity(char symbol, int colour, Position pos)
    : symbol{symbol}, colour{colour}, pos{pos} {
    entity = EntityType::UNINITIALIZED; // Default to uninitialized
}
Entity::~Entity() {}
EntityType Entity::getEntityType() {
    return entity;
}
char Entity::getSymbol() const { return symbol; }
int Entity::getColour() const { return colour; }
Position Entity::getPos() const { return pos; }
bool Entity::isSpace() const {
    return (symbol == '.' || symbol == '#' || symbol == '+' || || symbol == '/' 
                ||symbol == 'G');
}
bool Entity::isFloor() const {
    return (symbol == '.');
}
