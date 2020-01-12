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

    virtual QString notation() const;
    virtual OperationType type() const;

    virtual Operation* clone() const = 0;

protected:
    Operation();
    Operation(QString notation, OperationType type);
    QString operNotation;
    OperationType operType;
};


