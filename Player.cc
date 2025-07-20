export module player;

import enums;
import playerfactory;
import character;

export class Player: public Character {
    PlayerRace Race;
    int Gold;
  public:
    Player(PlayerRace race);
    virtual ~Player() = default;
    PlayerRace getRace() const;
    int getGold() const;
    void gainGold(int amount);
    virtual void onKill();
    virtual void onTurn(); // e.g. troll regenerates HP (default no-op)
};
