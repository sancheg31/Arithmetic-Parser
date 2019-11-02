#pragma once

#include <QString>
#include <QVariant>

class Operation {
public:

    enum class OperationType {
        UnaryOperation,
        BinaryOperation,
        Function
    };

    virtual ~Operation();
    virtual QString notation() const = 0;
    virtual OperationType type() const = 0;

};


