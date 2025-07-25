export module concretetiles;

import enums;
import position;
import tile;


export class Nothing : public Tile {
  public:
    Nothing(Position pos);
    ~Nothing() = default;
};

export class VerticalWall : public Tile {
  public:
    VerticalWall(Position pos);
    ~VerticalWall() = default;
};

export class HorizontalWall : public Tile {
  public:
    HorizontalWall(Position pos);
    ~HorizontalWall() = default;
};

export class Floor : public Tile {
  public:
    Floor(Position pos);
    ~Floor() = default;
};

export class Stair : public Tile {
  public:
    Stair(Position pos);
    ~Stair() = default;
};

export class Door : public Tile {
  public:
    Door(Position pos);
    ~Door() = default;
};

export class Corridor : public Tile {
  public:
    Corridor(Position pos);
    ~Corridor() = default;
};
