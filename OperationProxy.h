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
private:
    Operation* operation;
};

