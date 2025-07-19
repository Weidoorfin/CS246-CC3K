# CS246-CC3K
### Jul 18 update
- Added Game wrapper class which owns floor, player, text display
- Game's setDisplay() sets up the display (can add different display option later)
- Game's init() method initializes a new game.
- Game's run method keeps the game running.
    - It has a loop constantly checking player and floor's status

- Enhancement: add base class for textdisplay and graphics display. Can choose
- between which display to use. 

- Modify UML: Made floor a Subject, made enemy has-a player
- Floor contains chamber, enemy, item, and stair
- Floor's init() initializes floor, generates enemies

- Made Entity Abstract
- Made Position struct. Removed getPosition() -- unnecesary :((((

- Made atk, def, maxhp private: they are not intended to be changed in player / enemy after creation
- Implemnted getatk, getmaxhp, getdef. Player decorator will modify getatk, getdef to simulate temporary effects
- Removed virtual methods in character. Character will not be used for runtime polymorphism since player and enemy
- are fundamentally different.

- Enemy move / attack logic depend on player move. Use observer pattern for this. Floor does not control movement of enemy.
- Removed generator method for potion and treasure inside item class -- need to use separate factory since potion and treasure is-a item cant have generator inside item.
- 