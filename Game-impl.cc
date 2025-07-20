module game;

void Game::init() {
    currFloor = 1;
    td->startgame();
    // TODO: read in first floor from emptyfloor.txt
    player = std::make_unique<Player>(PlayerRace::Shade);
    // Initialize floor, player, and display
    floor = std::make_unique<Floor>(); 
    td = std::make_unique<TextDisplay>(); 
    flor->attach(td);
    floor->init(); // initialize floor, spawning enemy and items, attach textdisplay
    Merchant::hostile = false; // Merchant starts as non-hostile
}

void Game::run() {
    while (player->isAlive()) {  
        // Game loop will keep running until the player dies
        // Check if player has reached stairs or performs any action.
        if (floor->isComplete()) {
            if (currFloor < MAXFLOOR)
            ++currfloor;
            // replace current floor with new floor
            floor = make_unique<Floor>();
            // TODO: read in current floor from emptyfloor.txt
            floor->attach(td);
            floor->init(); 
        }
    }
    endGame();
}

void Game::endGame() {
    std::cout << "Game Over! Player has died.\n";
    // Clean up the game. Game is ready to be initialized again for reuse
    // TODO:
}
