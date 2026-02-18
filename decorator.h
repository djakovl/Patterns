#pragma once
#include <iostream>
#include <memory>
#include <string>

class DecComponent {
public:
    virtual ~DecComponent() = default;
    virtual std::string operation() const = 0;
};

class ConcreteDecComponent : public DecComponent {
public:
    std::string operation() const override {
        return "ConcreteDecComponent";
    }
};

class Decorator : public DecComponent {
protected:
    std::unique_ptr<DecComponent> component;
public:
    Decorator(std::unique_ptr<DecComponent> c) : component(std::move(c)) {}
    std::string operation() const override {
        return component->operation();
    }
};

class ConcreteDecoratorA : public Decorator {
public:
    ConcreteDecoratorA(std::unique_ptr<DecComponent> c) : Decorator(std::move(c)) {}
    std::string operation() const override {
        return "DecoratorA( " + Decorator::operation() + " )";
    }
};

class ConcreteDecoratorB : public Decorator {
public:
    ConcreteDecoratorB(std::unique_ptr<DecComponent> c) : Decorator(std::move(c)) {}
    std::string operation() const override {
        return "DecoratorB( " + Decorator::operation() + " )";
    }
};
