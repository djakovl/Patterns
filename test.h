#pragma once
#include <iostream>
#include <memory>
#include <string>
#include <vector>

#include "composite.h"
#include "decorator.h"
#include "facade.h"
#include "flyweight.h"
#include "proxy.h"
#include "iterator.h"
#include "mediator.h"
#include "memento.h"
#include "observer.h"
#include "state.h"
#include "strategy.h"
#include "templateMethod.h"
#include "visitor.h"

void testComposite() {
    std::cout << "=== Composite ===\n";
    auto root = std::make_unique<Composite>("root");
    auto branch = std::make_unique<Composite>("branch");
    branch->add(std::make_unique<Leaf>("leaf1"));
    branch->add(std::make_unique<Leaf>("leaf2"));
    root->add(std::move(branch));
    root->add(std::make_unique<Leaf>("leaf3"));
    root->operation();
}

void testDecorator() {
    std::cout << "\n=== Decorator ===\n";
    auto comp = std::make_unique<ConcreteComponent>();
    auto decA = std::make_unique<ConcreteDecoratorA>(std::move(comp));
    auto decB = std::make_unique<ConcreteDecoratorB>(std::move(decA));
    std::cout << decB->operation() << "\n";
}

void testFacade() {
    std::cout << "\n=== Facade ===\n";
    Facade facade;
    std::cout << facade.operation() << "\n";
}

void testFlyweight() {
    std::cout << "\n=== Flyweight ===\n";
    FlyweightFactory factory;
    auto fw1 = factory.getFlyweight("shared");
    auto fw2 = factory.getFlyweight("shared"); // переиспользован
    auto fw3 = factory.getFlyweight("other");
    fw1->operation("unique1");
    fw2->operation("unique2");
    fw3->operation("unique3");
}

void testProxy() {
    std::cout << "\n=== Proxy ===\n";
    Proxy proxy;
    proxy.request();
}

void testIterator() {
    std::cout << "\n=== Iterator ===\n";
    ConcreteAggregate agg;
    agg.addItem("item1");
    agg.addItem("item2");
    agg.addItem("item3");
    auto it = agg.createIterator();
    while (it->hasNext())
        std::cout << it->next() << "\n";
}

void testMediator() {
    std::cout << "\n=== Mediator ===\n";
    ComponentA compA;
    ComponentB compB;
    ConcreteMediator mediator(&compA, &compB);
    compA.doA();
    compB.doB();
}

void testMemento() {
    std::cout << "\n=== Memento ===\n";
    Originator originator;
    Caretaker caretaker(originator);
    originator.setState("state1");
    caretaker.backup();
    originator.setState("state2");
    caretaker.backup();
    originator.setState("state3");
    caretaker.undo();
    caretaker.undo();
}

void testObserver() {
    std::cout << "\n=== Observer ===\n";
    Subject subject;
    ConcreteObserverA obsA;
    ConcreteObserverB obsB;
    subject.attach(&obsA);
    subject.attach(&obsB);
    subject.setState("event1");
    subject.detach(&obsA);
    subject.setState("event2");
}

void testState() {
    std::cout << "\n=== State ===\n";
    Context ctx(std::make_unique<ConcreteStateA>());
    ctx.request();
    ctx.request();
    ctx.request();
}

void testStrategy() {
    std::cout << "\n=== Strategy ===\n";
    Context ctx;
    std::vector<int> data = {3, 1, 4, 1, 5};
    ctx.setStrategy(std::make_unique<ConcreteStrategyA>());
    ctx.executeStrategy(data); // по возрастанию
    ctx.setStrategy(std::make_unique<ConcreteStrategyB>());
    ctx.executeStrategy(data); // по убыванию
}

void testTemplateMethod() {
    std::cout << "\n=== Template Method ===\n";
    ConcreteClassA a;
    a.templateMethod();
    ConcreteClassB b;
    b.templateMethod();
}

void testVisitor() {
    std::cout << "\n=== Visitor ===\n";
    std::vector<std::unique_ptr<Element>> elements;
    elements.push_back(std::make_unique<ConcreteElementA>());
    elements.push_back(std::make_unique<ConcreteElementB>());
    ConcreteVisitor1 v1;
    ConcreteVisitor2 v2;
    for (const auto& e : elements) e->accept(v1);
    for (const auto& e : elements) e->accept(v2);
}

void runAllTests() {
    testComposite();
    testDecorator();
    testFacade();
    testFlyweight();
    testProxy();
    testIterator();
    testMediator();
    testMemento();
    testObserver();
    testState();
    testStrategy();
    testTemplateMethod();
    testVisitor();
}
