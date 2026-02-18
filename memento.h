#pragma once
#include <iostream>
#include <memory>
#include <vector>
#include <string>

class Memento {
    std::string state;
public:
    Memento(const std::string& s) : state(s) {}
    std::string getState() const { return state; }
};

class Originator {
    std::string state;
public:
    void setState(const std::string& s) {
        state = s;
        std::cout << "Originator: state = " << state << "\n";
    }
    std::unique_ptr<Memento> save() const {
        return std::make_unique<Memento>(state);
    }
    void restore(const Memento& m) {
        state = m.getState();
        std::cout << "Originator: restored state = " << state << "\n";
    }
};

class Caretaker {
    Originator& originator;
    std::vector<std::unique_ptr<Memento>> history;
public:
    Caretaker(Originator& o) : originator(o) {}
    void backup() {
        history.push_back(originator.save());
    }
    void undo() {
        if (history.empty()) return;
        originator.restore(*history.back());
        history.pop_back();
    }
};
