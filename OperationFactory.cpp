#include "OperationFactory.h"


OperationProxy* OperationFactory::createBinaryOperation(BinaryOperation::function_type op, const QString& notation) const {
    return new OperationProxy(new BinaryOperation(op, notation));
}

OperationProxy* OperationFactory::createUnaryOperation(UnaryOperation::function_type op, const QString& notation) const {
    return new OperationProxy(new UnaryOperation(op, notation));
}
