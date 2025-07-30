module item;

import <memory>;
import entity;
import player;
import position;

Item::Item(char symbol, int colour, Position pos)
    : Entity{symbol, colour, pos} {}

