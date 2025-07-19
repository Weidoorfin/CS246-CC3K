export module observer;

export class Observer {
  public:
    virtual void notify(Subject &whoFrom) = 0;
    virtual ~Observer() = default;
};
