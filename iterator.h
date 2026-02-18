#pragma once
#include <iostream>
#include <vector>
#include <string>

class Iterator {
public:
    virtual ~Iterator() = default;
    virtual bool hasNext() const = 0;
    virtual std::string next() = 0;
};

class Aggregate {
public:
    virtual ~Aggregate() = default;
    virtual std::unique_ptr<Iterator> createIterator() const = 0;
};

class ConcreteIterator : public Iterator {
    const std::vector<std::string>& data;
    size_t index = 0;
public:
    ConcreteIterator(const std::vector<std::string>& d) : data(d) {}
    bool hasNext() const override { return index < data.size(); }
    std::string next() override { return data[index++]; }
};

class ConcreteAggregate : public Aggregate {
    std::vector<std::string> items;
public:
    void addItem(const std::string& item) { items.push_back(item); }
    std::unique_ptr<Iterator> createIterator() const override {
        return std::make_unique<ConcreteIterator>(items);
    }
};
