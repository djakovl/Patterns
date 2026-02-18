#pragma once
#include <string>

class Product{
public:
	virtual ~Product() {};
	virtual std::string operation() const = 0;
};

class ConcreteProduct:public Product{
public:
	std::string operation() const override{
		return "{ConProd1}";
	}
};

class Creator{
public:
	virtual ~Creator() {};
	virtual Product* factoryMethod() const = 0;

	std::string someoperation() const {
		Product* product = this->factoryMethod();
		std::string result = "Creator: Ok " + product->operation();
		delete product;
		return result;
	}
};

class ConcreteCreator:public Creator{
	Product* factoryMethod() const override {
		return new ConcreteProduct();
	}
};