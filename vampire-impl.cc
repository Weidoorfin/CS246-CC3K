module vampire;

Vampire::Vampire() : Player(PlayerRace::VAMPIRE) {
    maxHP = 50;
    atk = 25;
    def = 25;
    currentHP = 50;
}

(50 HP, 25 Atk, 25 Def, gains 5 HP every successful attack and has no maximum HP) 
override onHit() and attack() behavior so it doesn't clamp HP increases.