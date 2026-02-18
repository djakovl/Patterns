#pragma once
#include <iostream>
#include <memory>
#include <string>
#include <vector>

// ---- Продукт ----
class ProductBuilder {
public:
    std::vector<std::string> parts;

    void show() const {
        std::cout << "Product parts: ";
        for (size_t i = 0; i < parts.size(); ++i) {
            std::cout << parts[i];
            if (i + 1 < parts.size()) std::cout << ", ";
        }
        std::cout << "\n";
    }
};

// ---- Интерфейс Builder ----
class Builder {
public:
    virtual ~Builder() = default;
    virtual void buildPartA() = 0;
    virtual void buildPartB() = 0;
    virtual void buildPartC() = 0;
};

// ---- ConcreteBuilder ----
class ConcreteBuilder : public Builder {
    std::unique_ptr<ProductBuilder> product;
public:
    ConcreteBuilder() {
        reset();
    }

    void reset() {
        product = std::make_unique<ProductBuilder>();
    }

    void buildPartA() override {
        product->parts.push_back("PartA");
    }
    void buildPartB() override {
        product->parts.push_back("PartB");
    }
    void buildPartC() override {
        product->parts.push_back("PartC");
    }

    // Отдаёт готовый продукт и сбрасывает состояние
    std::unique_ptr<ProductBuilder> GetResult() {
        auto result = std::move(product);
        reset();
        return result;
    }
};

// ---- Director ----
// Знает порядок шагов, но не знает конкретный Builder
class Director {
    Builder* builder = nullptr;
public:
    void setBuilder(Builder* b) {
        builder = b;
    }

    // Минимальная конфигурация
    void buildMinimal() {
        builder->buildPartA();
    }

    // Полная конфигурация
    void buildFull() {
        builder->buildPartA();
        builder->buildPartB();
        builder->buildPartC();
    }
};
