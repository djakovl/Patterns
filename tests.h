#pragma once

#include "chainOfResponsibility.h"
#include "command.h"
#include "factory.h"
#include "abstractFactory.h"
#include "builder.h"
#include "prototype.h"
#include "singletone.h"
#include "adapter.h"
#include "brige.h"
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

#include "structures.h"
#include "figure.h"
#include <iostream>


using namespace std;

void testFigure() {
    Figure* f1 = new SquareFig(3);
    Figure* f2 = new RoundFig(3);
    Figure* f3 = new TriangleFig(5, 3, 4);

    cout << "Square" << endl << "P = " << f1->area() << endl;
    cout << "S = " << f1->square() << endl;
    cout << "Round" << endl << "P = " << f2->area() << endl;
    cout << "S = " << f2->square() << endl;
    cout << "Triangle" << endl << "P = " << f3->area() << endl;
    cout << "S = " << f3->square() << endl;

    delete f1;
    delete f2;
    delete f3;
    return;
}

void testStructures() {

    cout << " Stack test \n";
    Stack st;
    cout << "empty(0-F, 1-T): " << st.isEmpty() << endl;
    st.push(1);
    st.push(2);
    st.push(3);
    cout << "top = " << st.peek() << endl;
    st.pop();
    cout << "top = " << st.peek() << endl;
    st.pop();
    cout << "top = " << st.peek() << endl;
    st.pop();
    cout << "empty(0-F, 1-T): " << st.isEmpty() << endl << endl;

    cout << " Queue test \n";
    Queue q;
    cout << "empty(0-F, 1-T): " << q.isEmpty() << endl;
    q.push(10);
    q.push(20);
    q.push(30);
    cout << "front (expect 10) = " << q.peek() << endl;
    q.pop();
    cout << "front (expect 20) = " << q.peek() << endl;
    q.pop();
    q.pop();
    cout << "empty(0-F, 1-T): " << q.isEmpty() << endl << endl;

    cout << " Deque test \n";
    Deque d;
    cout << "empty(0-F, 1-T): " << d.isEmpty() << endl;
    d.pushFront(5);        // [5]
    d.pushEnd(6);          // [5,6]
    d.pushFront(4);        // [4,5,6]
    d.pushEnd(7);          // [4,5,6,7]
    cout << "front (expect 4) = " << d.peekFront() << endl;
    cout << "end   (expect 7) = " << d.peekEnd() << endl;
    d.popFront();          // [5,6,7]
    d.popEnd();            // [5,6]
    cout << "front (expect 5) = " << d.peekFront() << endl;
    cout << "end   (expect 6) = " << d.peekEnd() << endl;
    d.popFront();
    d.popEnd();
    cout << "empty after pops (expect 1) = " << d.isEmpty() << endl << endl;

    cout << " BinaryTree test \n";
    BinaryTree bt;
    cout << "empty(0-F, 1-T): " << bt.isEmpty() << endl;

    bt.add(2);
    bt.add(4);
    bt.add(1);
    bt.add(5);
    bt.add(3);
    bt.add(16);
    bt.add(0);
    bt.add(29);

    cout << "DFS: ";
    bt.DFS();
    cout << endl;
    cout << "is_balanced before (0-F, 1-T): " << bt.isBalanced() << endl;
    bt.balance();
    cout << "DFS: ";
    bt.DFS();
    cout << endl;
    cout << "is_balanced after (0-F, 1-T): " << bt.isBalanced() << endl;

    cout << "\nDelete 3\n";
    bt.deleteNode(3);
    cout << "DFS after delete 3: ";
    bt.DFS();

    cout << "\nDelete 1,2,4,5\n";
    bt.deleteNode(1);
    bt.deleteNode(2);
    bt.deleteNode(4);
    bt.deleteNode(5);
    cout << "empty(0-F, 1-T): " << bt.isEmpty() << endl;
    return;
}


void testChain() {
    cout << "Test Chain" << endl;
    ConcreteHandler1 h1;
    ConcreteHandler2 h2;

    h1.setSuccessor(&h2);

    h1.handleRequest("Type1");
    h1.handleRequest("Type2");  

    cout << endl;
    return;
}


void testCommand() {
    cout << "Test Command" << endl;
    Receiver receiver;
    Invoker invoker;

    invoker.executeCommand(new ConcreteCommand(&receiver));
    cout << endl;
    return;
}

void testFactory() {
    cout << "Test factory" << endl;
    cout << "App: Launched with the ConcreteCreator1.\n";
    Creator* creator = new ConcreteCreator();
    creator->someoperation();
    cout << endl;
    return;
}

void testAbstractFactory(const AbstractFactory& factory) {
    cout << "Test Abstract Factory" << endl;
    auto productA = factory.createProductA();
    auto productB = factory.createProductB();
    
    cout << productA->operationA() << "\n";
    cout << productB->collaborate(*productA) << "\n";
    cout << endl;
    return;
}

void testBuilder() {
    cout << "testBuilder" << endl;
    Director director;
    ConcreteBuilder builder;
    director.setBuilder(&builder);

    cout << "Minimal product:\n";
    director.buildMinimal();
    auto p1 = builder.GetResult();
    p1->show();

    cout << "\nFull product:\n";
    director.buildFull();
    auto p2 = builder.GetResult();
    p2->show();

    // Без Director — клиент сам управляет шагами
    cout << "\nCustom product:\n";
    builder.buildPartA();
    builder.buildPartC();
    auto p3 = builder.GetResult();
    p3->show();
    cout << endl;
    return;
}

void testPrototype() {
    cout << "testPrototype" << endl;
    ConcretePrototype1 p1("Hello");
    ConcretePrototype2 p2(42);

    auto copy1 = p1.clone();
    auto copy2 = p2.clone();

    static_cast<ConcretePrototype1*>(copy1.get())->show();
    static_cast<ConcretePrototype2*>(copy2.get())->show();
    cout << endl;
    return;
}
void testSingletone() {
    cout << "testSingletone" << endl;
    Singleton* s1 = Singleton::Instance();
    Singleton* s2 = Singleton::Instance();
    s1->Singletonoperation();
    s2->Singletonoperation();

    // Один и тот же объект
    cout << (s1 == s2 ? "Один экземпляр" : "Разные экземпляры") << "\n";
    cout << endl;
    return;
}

void testAdapter() {
    cout << "testAdapter" << endl;
    Adaptee adaptee;
    ConcreteAdapter adapter(&adaptee);
    cout << adapter.operation() << "\n";
    cout << endl;
    return;
}

void testBrige() {
    // Abstraction + ImplementorA
    clientCode(Abstraction(make_unique<ConcreteImplementorA>()));

    // Abstraction + ImplementorB
    clientCode(Abstraction(make_unique<ConcreteImplementorB>()));

    // ExtendedAbstraction + ImplementorA
    clientCode(ExtendedAbstraction(make_unique<ConcreteImplementorA>()));

    return;
}

void testComposite() {
    std::cout << "Composite \n";
    auto root = std::make_unique<Composite>("root");
    auto branch = std::make_unique<Composite>("branch");
    branch->add(std::make_unique<Leaf>("leaf1"));
    branch->add(std::make_unique<Leaf>("leaf2"));
    root->add(std::move(branch));
    root->add(std::make_unique<Leaf>("leaf3"));
    root->operation();
}

void testDecorator() {
    std::cout << "Decorator \n";
    auto comp = std::make_unique<ConcreteDecComponent>();
    auto decA = std::make_unique<ConcreteDecoratorA>(std::move(comp));
    auto decB = std::make_unique<ConcreteDecoratorB>(std::move(decA));
    std::cout << decB->operation() << "\n";
}

void testFacade() {
    std::cout << "Facade \n";
    Facade facade;
    std::cout << facade.operation() << "\n";
}

void testFlyweight() {
    std::cout << "\n=== Flyweight ===\n";
    FlyweightFactory factory;
    auto fw1 = factory.getFlyweight("shared");
    auto fw2 = factory.getFlyweight("shared");
    auto fw3 = factory.getFlyweight("other");
    fw1->operation("unique1");
    fw2->operation("unique2");
    fw3->operation("unique3");

    UnsharedConcreteFlyweight unshared("allMyState");
    unshared.operation("unique4");
}


void testProxy() {
    std::cout << "Proxy \n";
    Proxy proxy;
    proxy.request();
}

void testIterator() {
    std::cout << "Iterator \n";
    ConcreteAggregate agg;
    agg.addItem("item1");
    agg.addItem("item2");
    agg.addItem("item3");
    auto it = agg.createIterator();
    while (it->hasNext())
        std::cout << it->next() << "\n";
}

void testMediator() {
    std::cout << "Mediator \n";
    ComponentA compA;
    ComponentB compB;
    ConcreteMediator mediator(&compA, &compB);
    compA.doA();
    compB.doB();
}

void testMemento() {
    std::cout << "Memento \n";
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
    std::cout << "Observer \n";
    SubjectObs subject;
    ConcreteObserverA obsA;
    ConcreteObserverB obsB;
    subject.attach(&obsA);
    subject.attach(&obsB);
    subject.setState("event1");
    subject.detach(&obsA);
    subject.setState("event2");
}

void testState() {
    std::cout << "State \n";
    StateContext ctx(std::make_unique<ConcreteStateA>());
    ctx.request();
    ctx.request();
    ctx.request();
}

void testStrategy() {
    std::cout << "Strategy \n";
    StrategyContext ctx;
    std::vector<int> data = { 3, 1, 4, 1, 5 };
    ctx.setStrategy(std::make_unique<ConcreteStrategyA>());
    ctx.executeStrategy(data);
    ctx.setStrategy(std::make_unique<ConcreteStrategyB>());
    ctx.executeStrategy(data);
}

void testTemplateMethod() {
    std::cout << "Template Method \n";
    ConcreteClassA a;
    a.templateMethod();
    ConcreteClassB b;
    b.templateMethod();
}

void testVisitor() {
    std::cout << "Visitor \n";
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
