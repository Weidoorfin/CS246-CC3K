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
    virtual int getGold() const;
    virtual int getTotGold() const;  // return amount of gold obtained in total
    void gainGold(int amount);
    virtual void onKill();
    virtual void onTurn(); // e.g. troll regenerates HP (default no-op)
    virtual void loseHP(int dec);
    virtual void gainHP(int inc);


    virtual std::unique_ptr<Player> reset() const = 0;
    
    // Unified potion application
    virtual std::unique_ptr<Player> applyEffect(const Potion &potion) = 0;
};
