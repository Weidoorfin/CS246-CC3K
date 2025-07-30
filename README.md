# CS246 - Chamber Crawler 3000 (CC3K)

A rogue-like game with command line style

## Player Manual

### DLC content
You can start the game with the executable cc3k in the folder, simply input command `./cc3k` to start the game. Also, the game supports two command-line arguments. The first one can be a `*.txt` file that has a fully generated floor. In this case, run the game with argument `./cc3k example.txt`. Also second arguments is an integer indicating the seed for random number generator. `./cc3k example.txt 123456` is the proper way to use it.

Upon start, the program will ask you whether to activate DLC or not. Simply input `DLC` to activate DLC and any other inputs will disable DLC content.

### Race selection
upon entering the game, the program will ask you to choose a race, please input **exact** race you want to choose, such as `Shade`, `Goblin`, then the system will tell your their stats and abilities. Input `y` to confirm choice, any other inputs will return to race choice stage.

### Display
Entering the game, a grid will be displayed. Different entities are shown in different colours.
- Blue: 
    - `@` indicating player position
    - `\` indicating next floor position
- Red: indicating all enemies, symbols differ by their type
- Yellow: indicating all treasures
- Green: indicating all potions

### In-game Commands
After entering the game, you can input the following commands:
- `dir` The direction you want to travel to
- `a dir` The direction you want to attack
- `u dir` The direction you want to use item at
- `f` Toggle enemy movements
- `e` End current round
- `r` Restart game
- `q` Quit game
> Dir here refers to a direction, directions are one of `N, NW, W, SW, S, SE, E, NE`
Any 