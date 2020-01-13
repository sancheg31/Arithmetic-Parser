#pragma once

#include "Operation.h"
#include "BinaryOperation.h"
#include "UnaryOperation.h"

class OperationProxy: public Operation
{
public:
    OperationProxy(Operation*);

    BinaryOperation* tryCastToBinary() const;
    UnaryOperation* tryCastToUnary() const;

    virtual OperationType type() const override;
    virtual QString notation() const override;
    virtual OperationProxy* clone() const override;
private:
    Operation* operation;
};

