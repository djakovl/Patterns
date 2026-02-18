#pragma once
#include <string>
#include <memory>
#include <iostream>

//Продукты A
class AbstractProductA {
public:
    virtual ~AbstractProductA() = default;
    virtual std::string operationA() const = 0;
};

class ConcreteProductA1 : public AbstractProductA {
public:
    std::string operationA() const override {
        return "{ProductA1}";
    }
};

class ConcreteProductA2 : public AbstractProductA {
public:
    std::string operationA() const override {
        return "{ProductA2}";
    }
};

//Продукты B
class AbstractProductB {
public:
    virtual ~AbstractProductB() = default;
    virtual std::string operationB() const = 0;
    virtual std::string collaborate(const AbstractProductA& a) const = 0;
};

class ConcreteProductB1 : public AbstractProductB {
public:
    std::string operationB() const override {
        return "{ProductB1}";
    }
    std::string collaborate(const AbstractProductA& a) const override {
        return "B1 collaborates with " + a.operationA();
    }
};

class ConcreteProductB2 : public AbstractProductB {
public:
    std::string operationB() const override {
        return "{ProductB2}";
    }
    std::string collaborate(const AbstractProductA& a) const override {
        return "B2 collaborates with " + a.operationA();
    }
};

//Абстрактная фабрика
class AbstractFactory {
public:
    virtual ~AbstractFactory() = default;
    virtual std::unique_ptr<AbstractProductA> createProductA() const = 0;
    virtual std::unique_ptr<AbstractProductB> createProductB() const = 0;
};

// Фабрика 1 — создаёт продукты семейства 1
class ConcreteFactory1 : public AbstractFactory {
public:
    std::unique_ptr<AbstractProductA> createProductA() const override {
        return std::make_unique<ConcreteProductA1>();
    }
    std::unique_ptr<AbstractProductB> createProductB() const override {
        return std::make_unique<ConcreteProductB1>();
    }
};

// Фабрика 2 — создаёт продукты семейства 2
class ConcreteFactory2 : public AbstractFactory {
public:
    std::unique_ptr<AbstractProductA> createProductA() const override {
        return std::make_unique<ConcreteProductA2>();
    }
    std::unique_ptr<AbstractProductB> createProductB() const override {
        return std::make_unique<ConcreteProductB2>();
    }
};

