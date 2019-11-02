#pragma once

#include "Operation.h"

class UnaryOperation: public Operation {
public:
    virtual ~UnaryOperation() override;
    virtual OperationType type() const override { return OperationType::UnaryOperation; }
    virtual QVariant operator()(QVariant v) const { return op(v); }
    virtual QString notation() const override { return opNotation; }

private:
    std::function<QVariant(QVariant)> op;
    QString opNotation;
};
