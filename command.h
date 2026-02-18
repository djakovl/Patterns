#include <iostream>
#include <vector>

class Receiver {
public:
    void Action() {
        std::cout << "Receiver: выполн€ю действие\n";
    }
};

class Command {
public:
    virtual ~Command() = default;
    virtual void Execute() = 0;
};

class ConcreteCommand : public Command {
    Receiver* receiver;
public:
    ConcreteCommand(Receiver* r) : receiver(r) {}

    void Execute() override {
        receiver->Action();
    }
};

class Invoker {
    std::vector<Command*> history;
public:
    void executeCommand(Command* cmd) {
        cmd->Execute();
        history.push_back(cmd);
    }

    ~Invoker() {
        for (auto* cmd : history) delete cmd;
    }
};
