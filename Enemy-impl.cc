module enemy;

import <random>;
import <algorithm>;
import <chrono>;
import <vector>;
import enums;
import character;
import player;


// Helper function to generate a random array of unique directions
// this random array can be used in randomMove to try moving in a random direction
// until a valid move is found.
vector<Direction> genDirections() {
    std::vector<Direction> directions{
        Direction::N, Direction::NE, Direction::E, Direction::SE,
        Direction::S, Direction::SW, Direction::W, Direction::NW
    };
    // default time-based seed
    unsigned seed = std::chrono::system_clock::now().time_since_epoch().count();
    // TODO: set seed to global seed variable if it exists

    std::default_random_engine rng{seed};
    std::shuffle(directions.begin(), directions.end(), rng);
    return directions; // return a random direction
}

Enemy::Enemy(EnemyType type, Player &player, Chamber &chamber, int maxHP, int atk, int def)
    : Character{chamber, maxHP, atk, def}, type{type}, player{player} {}

Enemy::randomMove() {
    std::vector<Direction> possibleMoves = genDirections();
    for (const Direction &dir : possibleMoves) {
        if (move(dir)) {
            return; // if the move is valid, return
        }
    }
}

Enemy::isInRange(Position pos) const {
    // Check if the position is within the range of the enemy
    return (pos.x >= pos.x - 1 && pos.x <= pos.x + 1 &&
            pos.y >= pos.y - 1 && pos.y <= pos.y + 1);
}

Enemy::attack() {
    // Implement the attack logic
    if (isInRange(player.getPos())) {
        player.onHit(*this); // Call onHit on the target character
    }
}

// default implementation of update
Enemy::update() {
    // Default implementation: random move if the player is not in range
    if (!isInRange(player.getPos())) {
        randomMove();
    } else {
        // If the player is in range, attack the player
        attack();
    }
}
