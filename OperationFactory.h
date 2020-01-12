#pragma once

#include "Operation.h"
#include "UnaryOperation.h"
#include "BinaryOperation.h"
#include "OperationProxy.h"

class OperationFactory {
public:
    OperationProxy* createBinaryOperation(BinaryOperation::function_type op, const QString& notation) const;
    OperationProxy* createUnaryOperation(UnaryOperation::function_type op, const QString& notation) const;
};

