#pragma once
#include <iostream>
#include <memory>
#include <vector>
#include <string>

class Component {
public:
    virtual ~Component() = default;
    virtual void operation() const = 0;
    virtual void add(std::unique_ptr<Component> c) {}
    virtual void remove(Component* c) {}
};

class Leaf : public Component {
    std::string name;
public:
    Leaf(const std::string& n) : name(n) {}
    void operation() const override {
        std::cout << "Leaf: " << name << "\n";
    }
};

class Composite : public Component {
    std::string name;
    std::vector<std::unique_ptr<Component>> children;
public:
    Composite(const std::string& n) : name(n) {}
    void add(std::unique_ptr<Component> c) override {
        children.push_back(std::move(c));
    }
    void operation() const override {
        std::cout << "Composite: " << name << "\n";
        for (const auto& child : children)
            child->operation();
    }
};
