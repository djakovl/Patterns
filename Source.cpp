#include "tests.h"
#include <iostream>

int main() {
    setlocale(LC_ALL, "Rus");
    //testFactory();
    //testPrototype();
    //testChain();
    //testCommand();
    //testBuilder();
    //testAbstractFactory(ConcreteFactory1{});
    //testAbstractFactory(ConcreteFactory2{});
    //testSingletone();
    //testAdapter();
    //testBrige();
    //testComposite();
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
    return 0;
}

