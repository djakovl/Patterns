#pragma once
#include <iostream>
#include <string>

// Сложная подсистема
class SubsystemA {
public:
    std::string operationA() const { return "SubsystemA: ready"; }
    std::string operationAZ() const { return "SubsystemA: go!"; }
};

class SubsystemB {
public:
    std::string operationB() const { return "SubsystemB: ready"; }
    std::string operationBZ() const { return "SubsystemB: go!"; }
};

// Фасад — единая точка входа в подсистему
class Facade {
    SubsystemA sysA;
    SubsystemB sysB;
public:
    std::string operation() const {
        std::string result = "Facade initializes:\n";
        result += sysA.operationA() + "\n";
        result += sysB.operationB() + "\n";
        result += "Facade triggers:\n";
        result += sysA.operationAZ() + "\n";
        result += sysB.operationBZ();
        return result;
    }
};
