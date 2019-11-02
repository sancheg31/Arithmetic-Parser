#pragma once

#include <functional>

#include "Operation.h"

class BinaryOperation: public Operation {
public:

    BinaryOperation(std::function<QVariant(QVariant, QVariant)>, const QString&);
    BinaryOperation(const BinaryOperation&);
    BinaryOperation& operator=(const BinaryOperation&);

    virtual ~BinaryOperation() override;
    virtual QVariant operator()(QVariant v1, QVariant v2) const { return op(v1, v2); }
    virtual OperationType type() const override { return OperationType::BinaryOperation; }
    virtual QString notation() const override { return opNotation; }

private:
    std::function<QVariant(QVariant, QVariant)> op;
    QString opNotation;
};
