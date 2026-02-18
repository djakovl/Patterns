#pragma once
#include <iostream>
#include <memory>
#include <string>

// ---- Интерфейс Implementor ----
class Implementor {
public:
    virtual ~Implementor() = default;
    virtual std::string operationImpl() const = 0;
};

// ---- ConcreteImplementorA ----
class ConcreteImplementorA : public Implementor {
public:
    std::string operationImpl() const override {
        return "ConcreteImplementorA: результат";
    }
};

// ---- ConcreteImplementorB ----
class ConcreteImplementorB : public Implementor {
public:
    std::string operationImpl() const override {
        return "ConcreteImplementorB: результат";
    }
};

// ---- Abstraction — хранит ссылку на Implementor (композиция = ромб на схеме) ----
class Abstraction {
protected:
    std::unique_ptr<Implementor> impl;
public:
    Abstraction(std::unique_ptr<Implementor> i) : impl(std::move(i)) {}
    virtual ~Abstraction() = default;

    virtual std::string operation() const {
        return "Abstraction: [ " + impl->operationImpl() + " ]";
    }
};

// ---- Расширенная абстракция (опционально) ----
class ExtendedAbstraction : public Abstraction {
public:
    ExtendedAbstraction(std::unique_ptr<Implementor> i) : Abstraction(std::move(i)) {}

    std::string operation() const override {
        return "ExtendedAbstraction: [ " + impl->operationImpl() + " ]";
    }
};

// ---- Client ----
void clientCode(const Abstraction& abstraction) {
    std::cout << abstraction.operation() << "\n";
}

