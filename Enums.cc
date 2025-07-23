export module enums;

export enum class Race {SHADE, DROW, VAMPIRE, TROLL, GOBLIN, HUMAN, DWARF, ELF, ORCS, MERCHANT, DRAGON, HALFLING};
export enum class Direction {N, NE, E, SE, S, SW, W, NW};
export enum class TreasureType {SMALL, NORMAL, MERCHANT, DRAGON};
export enum class GameState {Finish, Restart, Quit};
export enum class EntityType {UNINITIALIZED, PLAYER, ENEMY, POTION, TREASURE, TILE};
export enum class PotionType {BA, BD, PH, WA, WD, RH};
export enum class TileType {Nothing, VerticalWall, HorizontalWall, Floor, Stair, Door, Corridor};
