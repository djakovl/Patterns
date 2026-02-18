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
        std::cout << "RealSubject: proccessing request\n";
    }
};

class Proxy : public Subject {
    mutable std::unique_ptr<RealSubject> realSubject;

    bool checkAccess() const {
        std::cout << "Proxy: check request\n";
        return true;
    }
    void logAccess() const {
        std::cout << "Proxy: log request\n";
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
