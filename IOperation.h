#pragma once

#include <QString>
#include <QVariant>

class IOperation {
public:

    enum class OperationType {
        UnaryOperation,
        BinaryOperation
    };

    virtual ~IOperation();
    virtual QString notation() const;
    virtual OperationType type() const;

protected:
    IOperation(QString notation, OperationType type): operNotation(notation), type(operType) {}
    QString operNotation;
    OperationType operType;
};


