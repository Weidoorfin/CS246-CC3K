export module player;

import enums;
import playerfactory;
import character;

export class Player: public Character {
    PlayerRace Race;
    int Gold;
    int totGold; // amount gold obtained in total
  public:
    Player(PlayerRace race);
    virtual ~Player() = default;
    PlayerRace getRace() const;
    int getGold() const;
    int getTotGold() const;  // return amount of gold obtained in total
    void gainGold(int amount);
    virtual void onKill();
    virtual void onTurn(); // e.g. troll regenerates HP (default no-op)
    void loseHP(int dec);
    virtual void gainHP(int inc);

    
};
