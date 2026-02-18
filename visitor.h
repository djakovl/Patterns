#pragma once
#include <iostream>
#include <string>

class ConcreteElementA;
class ConcreteElementB;

class Visitor {
public:
    virtual ~Visitor() = default;
    virtual void visitElementA(const ConcreteElementA& e) const = 0;
    virtual void visitElementB(const ConcreteElementB& e) const = 0;
};

class Element {
public:
    virtual ~Element() = default;
    virtual void accept(const Visitor& v) const = 0;
};

class ConcreteElementA : public Element {
public:
    void accept(const Visitor& v) const override { v.visitElementA(*this); }
    std::string operationA() const { return "ElementA"; }
};

class ConcreteElementB : public Element {
public:
    void accept(const Visitor& v) const override { v.visitElementB(*this); }
    std::string operationB() const { return "ElementB"; }
};

class ConcreteVisitor1 : public Visitor {
public:
    void visitElementA(const ConcreteElementA& e) const override {
        std::cout << "Visitor1 + " << e.operationA() << "\n";
    }
    void visitElementB(const ConcreteElementB& e) const override {
        std::cout << "Visitor1 + " << e.operationB() << "\n";
    }
};

class ConcreteVisitor2 : public Visitor {
public:
    void visitElementA(const ConcreteElementA& e) const override {
        std::cout << "Visitor2 + " << e.operationA() << "\n";
    }
    void visitElementB(const ConcreteElementB& e) const override {
        std::cout << "Visitor2 + " << e.operationB() << "\n";
    }
};
