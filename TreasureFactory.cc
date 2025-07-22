export treasurefactory;

import <memory>;
import treasure;
import position;
import enums;

export class TreasureFactory {
public:
    static std::unique_ptr<Treasure> createTreasure(TreasureType type, Position pos);
};
