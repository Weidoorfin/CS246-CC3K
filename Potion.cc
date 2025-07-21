export module potion;

export class Potion : public Item {
public:
    virtual ~Potion() = default;
    virtual std::unique_ptr<Player> applyEffect(std::unique_ptr<Player> player) const = 0;
};
