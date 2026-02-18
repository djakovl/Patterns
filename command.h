#include <iostream>
#include <vector>

// Receiver Ч бизнес-логика
class Receiver {
public:
    void Action() {
        std::cout << "Receiver: выполн€ю действие\n";
    }
};

// »нтерфейс Command
class Command {
public:
    virtual ~Command() = default;
    virtual void Execute() = 0;
};

// ConcreteCommand
class ConcreteCommand : public Command {
    Receiver* receiver;
public:
    ConcreteCommand(Receiver* r) : receiver(r) {}

    void Execute() override {
        receiver->Action();
    }
};

// Invoker
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
