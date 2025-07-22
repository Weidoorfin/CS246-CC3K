export module enums;

enum class Race {SHADE, DROW, VAMPIRE, TROLL, GOBLIN, HUMAN, DWARF, ELF, ORCS, MERCHANT, DRAGON, HALFLING};
enum class Direction {N, NE, E, SE, S, SW, W, NW};
enum class PotionType {BA, BD, PH, WA, WD, RH};
enum class GameState {Finish, Restart, Quit};
enum class EntityType {UNINITIALIZED, PLAYER, ENEMY, POTION, TREASURE};
enum class TileType {VerticalWall, HorizontalWall, Floor, Stair, Door, Player, Enemy, Potion, Gold, Nothing, Corridor};
