export module treasurefactory;

import <memory>;
import treasure;
import position;
import enums;

export class TreasureFactory {
public:
    // Creates a treasure of the specified type. 
    static std::unique_ptr<Treasure> createTreasure(TreasureType type, Position pos);
};
