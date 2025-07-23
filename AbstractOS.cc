export module abstractos;

import <vector>;

export class Observer;

export class Subject {
    std::vector<Observer*> observers;
  public:
    void attach(Observer *o);
    void detach(Observer *o);
    void notifyObservers();
    virtual ~Subject() = 0;
};

class Observer {
  public:
    virtual void notify(Subject &whoFrom) = 0;
    virtual ~Observer() = default;
};
