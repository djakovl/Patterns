#pragma once
#include <iostream>
#include <memory>
#include <map>
#include <string>

class Flyweight {
public:
    virtual ~Flyweight() = default;
    virtual void operation(const std::string& extrinsicState) const = 0;
};

class ConcreteFlyweight : public Flyweight {
    std::string intrinsicState;
public:
    ConcreteFlyweight(const std::string& state) : intrinsicState(state) {}
    void operation(const std::string& extrinsicState) const override {
        std::cout << "ConcreteFlyweight: intrinsic=[ " << intrinsicState
            << " ] extrinsic=[ " << extrinsicState << " ]\n";
    }
};

class UnsharedConcreteFlyweight : public Flyweight {
    std::string allState;
public:
    UnsharedConcreteFlyweight(const std::string& state) : allState(state) {}
    void operation(const std::string& extrinsicState) const override {
        std::cout << "UnsharedFlyweight: allState=[ " << allState
            << " ] extrinsic=[ " << extrinsicState << " ]\n";
    }
};

class FlyweightFactory {
    std::map<std::string, std::shared_ptr<Flyweight>> flyweights;
public:
    std::shared_ptr<Flyweight> getFlyweight(const std::string& key) {
        if (flyweights.find(key) == flyweights.end()) {
            flyweights[key] = std::make_shared<ConcreteFlyweight>(key);
            std::cout << "FlyweightFactory: создан новый [\"" << key << "\"]\n";
        }
        else {
            std::cout << "FlyweightFactory: переиспользован [\"" << key << "\"]\n";
        }
        return flyweights[key];
    }
};