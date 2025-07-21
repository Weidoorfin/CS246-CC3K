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

##### Developent note - Frank Jul 19
- Enemy, character logic:
    - To maximize code reusability, move method is tied to character. Enemy implements a new method random move, which
    - calls character's move method with a ranodm direction. Enemy's random move method is used in their update() method.
    - Character is tied to a chamber. Its move method will check validity with the chamber reference and will return false if the move is invalid.
- Enemy becomes subject of the floor
    - Removed enemy as observer. Floor will call enemy's update(Position player's pos) method which will cause enemy to either
    - attack or move randomly.
    - on defeat, enemy will notify floor, who is responsible to perform corresponding behaviours 
    (i.e. if enemy type is HUman, floor should generate two pieces of gold)
        - Either floor get notified by enemy and check enemy type and perform actions based on the type of enemy defeated
        - Or enemy keeps a poitner to floor, and calls item factory to generate item inside floor
- Enemy has a reference to player
    - When initializing enemy, a reference to player is added
- Floor as the new observer
    - Floor is the observer to both player, enemy, and items. (see tutorial 7 for handling observer of different subjects).
- Enemy factory:
    - enemy factory requires a reference to chamber.

- UML Update continued
- Made floor a Subject AS WELL AS an Observer
- Floor contains chamber, enemy, item, and stair
- Floor's init() initializes floor, generates enemies

##### Development note - Jul 20
- Added enemyengine to centralize all enemy related operations and holding an
- enemy vector