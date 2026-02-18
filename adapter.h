#pragma once
#include <iostream>
#include <string>

class Adaptee {
public:
    std::string Adaptedoperation() const {
        return "Adaptee: результат adaptedoperation";
    }
};

class Adapter {
public:
    virtual ~Adapter() = default;
    virtual std::string operation() const = 0;
};

class ConcreteAdapter : public Adapter {
    Adaptee* adaptee;
public:
    ConcreteAdapter(Adaptee* a) : adaptee(a) {}

    std::string operation() const override {
        return "ConcreteAdapter: [ " + adaptee->Adaptedoperation() + " ]";
    }
};