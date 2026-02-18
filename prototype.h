#pragma once
#include <iostream>
#include <memory>
#include <string>

// ---- Èםעונפויס Prototype ----
class Prototype {
public:
    virtual ~Prototype() = default;
    virtual std::unique_ptr<Prototype> clone() const = 0;
};

// ---- ConcretePrototype1 ----
class ConcretePrototype1 : public Prototype {
    std::string field;
public:
    ConcretePrototype1(const std::string& f) : field(f) {}
    ConcretePrototype1(const ConcretePrototype1& other) : field(other.field) {}

    std::unique_ptr<Prototype> clone() const override {
        return std::make_unique<ConcretePrototype1>(*this);
    }

    void show() const {
        std::cout << "ConcretePrototype1: field = " << field << "\n";
    }
};

// ---- ConcretePrototype2 ----
class ConcretePrototype2 : public Prototype {
    int value;
public:
    ConcretePrototype2(int v) : value(v) {}
    ConcretePrototype2(const ConcretePrototype2& other) : value(other.value) {}

    std::unique_ptr<Prototype> clone() const override {
        return std::make_unique<ConcretePrototype2>(*this);
    }

    void show() const {
        std::cout << "ConcretePrototype2: value = " << value << "\n";
    }
};
