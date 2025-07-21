module item;

import entity;
import enums;

Item::Item(char symbol, int colour, Position pos)
    : Entity{symbol, colour, pos} {}