#pragma once
#include <iostream>
#include <list>
#include <string>

class Observer {
public:
    virtual ~Observer() = default;
    virtual void update(const std::string& event) = 0;
};

class SubjectObs {
    std::list<Observer*> observers;
    std::string state;
public:
    void attach(Observer* o) { observers.push_back(o); }
    void detach(Observer* o) { observers.remove(o); }
    void notify() {
        for (auto* o : observers)
            o->update(state);
    }
    void setState(const std::string& s) {
        state = s;
        std::cout << "SubjectObs: state = " << state << "\n";
        notify();
    }
};

class ConcreteObserverA : public Observer {
public:
    void update(const std::string& event) override {
        std::cout << "ObserverA: get event \"" << event << "\"\n";
    }
};

class ConcreteObserverB : public Observer {
public:
    void update(const std::string& event) override {
        std::cout << "ObserverB: get event \"" << event << "\"\n";
    }
};
