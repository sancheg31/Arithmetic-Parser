#pragma once

#include "Operation.h"
#include "BinaryOperation.h"
#include "UnaryOperation.h"

class OperationProxy: public Operation
{
public:
    OperationProxy(Operation*);
    Operation::OperationType::BinaryOperation tryCastToBinary() const;
    Operation::OperationType::UnaryOperation tryCastToUnary() const;
private:
    Operation* operation;
};

