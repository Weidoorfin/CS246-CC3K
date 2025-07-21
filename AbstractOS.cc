export module abstractos;

import <vector>;

class Observer;

export class Subject {
    std::vector<Observer*> observers;
  public:
    void attach(Observer *o);
    void detach(Observer *o);
    void notifyObservers();
    virtual ~Subject() = 0;
};

export class Observer {
  public:
    virtual void notify(Subject &whoFrom) = 0;
    virtual ~Observer() = default;
};
