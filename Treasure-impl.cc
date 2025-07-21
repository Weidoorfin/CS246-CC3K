module treasure;

import item;

Treasure::Treasure(int value) : value(value) {}

int Treasure::getValue() const {
    return value;
}
