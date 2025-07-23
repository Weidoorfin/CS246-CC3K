module chamber;

import randomengine;

bool Chamber::isWithPlayer() const {
    return withPlayer;
}

void Chamber::setWithPlayer() {
    withPlayer = true;
}

void Chamber::addTile(Position pos) {
    validArea.push_back({pos, false});
}

//

Position Chamber::getRandomTile() {
    int size = validArea.size();
    RandomEngine re;
    vector<int> indices = re.genIndices(0, size - 1);
    for (int idx : indices) {
        if (!validArea[idx].occupied) {
            validArea[idx].occupied = true; // Mark the tile as occupied
            return validArea[idx].pos; // Return the position of the unoccupied tile
        }
    }
}

bool Chamber::isValidTile(Status s) {
    return s.occupied;
}
