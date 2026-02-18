#pragma once
#include <iostream>

class AbstractClass {
public:
    virtual ~AbstractClass() = default;

    // Шаблонный метод — определяет скелет алгоритма
    void templateMethod() const {
        baseOperation();
        requiredOperation();
        hook();
    }
protected:
    void baseOperation() const {
        std::cout << "AbstractClass: baseOperation\n";
    }
    virtual void requiredOperation() const = 0;
    virtual void hook() const {} // необязательный шаг
};

class ConcreteClassA : public AbstractClass {
protected:
    void requiredOperation() const override {
        std::cout << "ConcreteClassA: requiredOperation\n";
    }
    void hook() const override {
        std::cout << "ConcreteClassA: hook (переопределён)\n";
    }
};

class ConcreteClassB : public AbstractClass {
protected:
    void requiredOperation() const override {
        std::cout << "ConcreteClassB: requiredOperation\n";
    }
    // hook не переопределяем — используется пустая версия
};
