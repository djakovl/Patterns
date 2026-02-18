#pragma once
#include <iostream>
#include <memory>

class StateContext;

class State {
public:
    virtual ~State() = default;
    virtual void handle(StateContext& ctx) = 0;
};

class StateContext {
    std::unique_ptr<State> state;
public:
    StateContext(std::unique_ptr<State> s) : state(std::move(s)) {}
    void setState(std::unique_ptr<State> s) { state = std::move(s); }
    void request() { state->handle(*this); }
};

class ConcreteStateA : public State {
public:
    void handle(StateContext& ctx) override;
};

class ConcreteStateB : public State {
public:
    void handle(StateContext& ctx) override {
        std::cout << "StateB: processing, go to A\n";
        ctx.setState(std::make_unique<ConcreteStateA>());
    }
};

inline void ConcreteStateA::handle(StateContext& ctx) {
    std::cout << "StateA: processing, go to  B\n";
    ctx.setState(std::make_unique<ConcreteStateB>());
}