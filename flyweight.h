#pragma once
#include <iostream>
#include <memory>
#include <map>
#include <string>

// Flyweight — хранит только общее (intrinsic) состояние
class Flyweight {
    std::string sharedState;
public:
    Flyweight(const std::string& state) : sharedState(state) {}
    void operation(const std::string& uniqueState) const {
        std::cout << "Flyweight: shared=[ " << sharedState
                  << " ] unique=[ " << uniqueState << " ]\n";
    }
};

// Фабрика Flyweight — переиспользует существующие объекты
class FlyweightFactory {
    std::map<std::string, std::shared_ptr<Flyweight>> flyweights;
public:
    std::shared_ptr<Flyweight> getFlyweight(const std::string& key) {
        if (flyweights.find(key) == flyweights.end()) {
            flyweights[key] = std::make_shared<Flyweight>(key);
            std::cout << "FlyweightFactory: new flyweight for \"" << key << "\"\n";
        } else {
            std::cout << "FlyweightFactory: old flyweight for \"" << key << "\"\n";
        }
        return flyweights[key];
    }
};
