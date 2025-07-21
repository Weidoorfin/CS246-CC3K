export module treasure;

import item;

export class Treasure : public Item {
    int value; // Amount of gold this treasure is worth
public:
    Treasure(int value);
    int getValue() const;
};