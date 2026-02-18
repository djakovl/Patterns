#pragma once
#include <iostream>
#include <string>

class BaseComponent;

class Mediator {
public:
    virtual ~Mediator() = default;
    virtual void notify(BaseComponent* sender, const std::string& event) const = 0;
};

class BaseComponent {
protected:
    Mediator* mediator = nullptr;
public:
    void setMediator(Mediator* m) { mediator = m; }
};

class ComponentA : public BaseComponent {
public:
    void doA() {
        std::cout << "ComponentA: doA\n";
        if (mediator) mediator->notify(this, "A");
    }
};

class ComponentB : public BaseComponent {
public:
    void doB() {
        std::cout << "ComponentB: doB\n";
        if (mediator) mediator->notify(this, "B");
    }
    void doC() {
        std::cout << "ComponentB: doC\n";
    }
};

class ConcreteMediator : public Mediator {
    ComponentA* compA;
    ComponentB* compB;
public:
    ConcreteMediator(ComponentA* a, ComponentB* b) : compA(a), compB(b) {
        compA->setMediator(this);
        compB->setMediator(this);
    }
    void notify(BaseComponent* sender, const std::string& event) const override {
        if (event == "A") {
            std::cout << "Mediator: reacting A, call doC\n";
            compB->doC();
        }
        if (event == "B") {
            std::cout << "Mediator: reacting B\n";
        }
    }
};
