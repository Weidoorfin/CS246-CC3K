module abstractos;

import <vector>;
import <algorithm>;

Subject::attach(Observer *o) {
    observers.push_back(o);
}
Subject::detach(Observer *o) {
    observers.erase(std::remove(observers.begin(), observers.end(), o), observers.end());
}
void Subject::notifyObservers() {
    for (Observer *o : observers) {
        o->notify(*this);
    }
}
Subject::~Subject() {}
