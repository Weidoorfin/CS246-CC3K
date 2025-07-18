export module subject;

import <vector>;

export class Subject {
    std::vector<Observer*> observers;
  public:
    void attach(Observer *o);
    void detach(Observer *o);
    void notifyObservers();
    virtual ~Subject() = 0;
};
