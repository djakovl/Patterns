#pragma once
#include <iostream>
#include <memory>
#include <vector>
#include <algorithm>

class Strategy {
public:
    virtual ~Strategy() = default;
    virtual std::vector<int> execute(const std::vector<int>& data) const = 0;
};

class ConcreteStrategyA : public Strategy {
public:
    std::vector<int> execute(const std::vector<int>& data) const override {
        auto result = data;
        std::sort(result.begin(), result.end());
        return result;
    }
};

class ConcreteStrategyB : public Strategy {
public:
    std::vector<int> execute(const std::vector<int>& data) const override {
        auto result = data;
        std::sort(result.begin(), result.end(), std::greater<int>());
        return result;
    }
};

class StrategyContext {
    std::unique_ptr<Strategy> strategy;
public:
    void setStrategy(std::unique_ptr<Strategy> s) { strategy = std::move(s); }
    void executeStrategy(const std::vector<int>& data) const {
        auto result = strategy->execute(data);
        for (int v : result) std::cout << v << " ";
        std::cout << "\n";
    }
};