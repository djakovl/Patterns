#include <iostream>
#include <string>

class Handler {
protected:
    Handler* successor = nullptr;
public:
    virtual ~Handler() = default;

    void setSuccessor(Handler* next) {
        successor = next;
    }

    virtual void handleRequest(const std::string& request) = 0;
};

class ConcreteHandler1 : public Handler {
public:
    void handleRequest(const std::string& request) override {
        if (request == "Type1") {
            std::cout << "Handler1: обрабатываю " << request << "\n";
        }
        else if (successor) {
            successor->handleRequest(request);
        }
    }
};

class ConcreteHandler2 : public Handler {
public:
    void handleRequest(const std::string& request) override {
        if (request == "Type2") {
            std::cout << "Handler2: обрабатываю " << request << "\n";
        }
        else if (successor) {
            successor->handleRequest(request);
        }
    }
};


