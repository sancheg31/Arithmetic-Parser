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

protected:
    Operation();
    Operation(QString notation, OperationType type): operNotation(notation), operType(type) { }
    QString operNotation;
    OperationType operType;
};


