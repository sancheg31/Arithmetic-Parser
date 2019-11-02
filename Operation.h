#pragma once

#include <QString>
#include <QVariant>

class Operation {
public:

    enum class OperationType {
        UnaryOperation,
        BinaryOperation
    };

    virtual ~Operation();
    virtual QString notation() const = 0;
    virtual OperationType type() const = 0;

};


