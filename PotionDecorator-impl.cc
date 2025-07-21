module potiondecorator;
    

PotionDecorator::PotionDecorator(std::unique_ptr<Player> wrapped) : 
    Player{wrapped->getRace()}, base{std::move(wrapped)} {}

int PotionDecorator::getAtk() const { return base->getAtk(); }
int PotionDecorator::getDef() const { return base->getDef(); }
int PotionDecorator::getGold() const { return base->getGold(); }
int PotionDecorator::getTotGold() const { return base->getTotGold(); }
int PotionDecorator::getMaxHP() const { return base->getMaxHP(); }
int PotionDecorator::getHP() const { return base->getHP(); } 

void PotionDecorator::onKill() { base->onKill(); }
void PotionDecorator::onTurn() { base->onTurn(); }

void PotionDecorator::gainHP(int inc) { base->gainHP(inc); }
void PotionDecorator::loseHP(int dec) { base->loseHP(dec); }

std::unique_ptr<Player> PotionDecorator::reset() {
    return base->reset();
}

std::unique_ptr<Player> PotionDecorator::applyEffect(std::unique_ptr<Player> player) const {
    return std::make_unique<PotionDecorator>(std::move(player));
}