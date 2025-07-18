export module position

export class Position {
    int x, y;
  public:
    Position(int x, int y);
    Position getPos() const;
    ~Position();
};
