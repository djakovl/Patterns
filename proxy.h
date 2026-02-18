#pragma once
#include <iostream>
#include <memory>
#include <string>

class Subject {
public:
    virtual ~Subject() = default;
    virtual void request() const = 0;
};

class RealSubject : public Subject {
public:
    void request() const override {
        std::cout << "RealSubject: обрабатываю запрос\n";
    }
};

// Proxy — контролирует доступ к RealSubject
class Proxy : public Subject {
    mutable std::unique_ptr<RealSubject> realSubject;

    bool checkAccess() const {
        std::cout << "Proxy: проверяю доступ\n";
        return true;
    }
    void logAccess() const {
        std::cout << "Proxy: логирую запрос\n";
    }
public:
    void request() const override {
        if (checkAccess()) {
            if (!realSubject)
                realSubject = std::make_unique<RealSubject>();
            realSubject->request();
            logAccess();
        }
    }
};
