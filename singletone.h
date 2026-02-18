#pragma once
#include <iostream>
#include <string>

class Singleton {
    static Singleton* uniqueInstance;
    std::string singletonData;

    Singleton(const std::string& data) : singletonData(data) {}

public:
    Singleton(const Singleton&) = delete;
    Singleton& operator=(const Singleton&) = delete;

    static Singleton* Instance() {
        if (!uniqueInstance)
            uniqueInstance = new Singleton("default");
        return uniqueInstance;
    }

    void Singletonoperation() {
        std::cout << "Singleton: data = " << singletonData << "\n";
    }
};

Singleton* Singleton::uniqueInstance = nullptr;
