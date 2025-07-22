export module enums;

enum class Race {SHADE, DROW, VAMPIRE, TROLL, GOBLIN, HUMAN, DWARF, ELF, ORCS, MERCHANT, DRAGON, HALFLING};
enum class Direction {N, NE, E, SE, S, SW, W, NW};
enum class PotionType {BA, BD, PH, WA, WD, RH};
enum class TreasureType {SMALL, NORMAL, MERCHANT, DRAGON};
enum class GameState {Finish, Restart, Quit};
enum class EntityType {UNINITIALIZED, PLAYER, ENEMY, POTION, TREASURE, TILE};
enum class TileType {Nothing, VerticalWall, HorizontalWall, Floor, Stair, Door, Corridor};
