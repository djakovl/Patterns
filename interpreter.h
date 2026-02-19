#pragma once
#include <iostream>
#include <string>
#include <memory>
#include <vector>

class Context {
    std::string input;
    std::string output;
public:
    Context(const std::string& in) : input(in) {}
    std::string getInput()  const { return input; }
    std::string getOutput() const { return output; }
    void setOutput(const std::string& out) { output = out; }
};

class AbstractExpression {
public:
    virtual ~AbstractExpression() = default;
    virtual void interpret(Context& ctx) const = 0;
};

class TerminalExpression : public AbstractExpression {
    std::string token;
public:
    TerminalExpression(const std::string& t) : token(t) {}

    void interpret(Context& ctx) const override {
        std::string out = ctx.getOutput();
        if (!out.empty()) out += " ";
        out += "[Terminal:" + token + "]";
        ctx.setOutput(out);
    }
};

class NonterminalExpression : public AbstractExpression {
    std::vector<std::shared_ptr<AbstractExpression>> children;
public:
    void add(std::shared_ptr<AbstractExpression> expr) {
        children.push_back(expr);
    }

    void interpret(Context& ctx) const override {
        for (const auto& child : children)
            child->interpret(ctx);
        std::string out = ctx.getOutput();
        out += " [Nonterminal applied]";
        ctx.setOutput(out);
    }
};
