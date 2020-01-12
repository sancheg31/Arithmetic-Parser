#include "OperationFactory.h"


OperationFactory* OperationFactory::instance() {
    static OperationFactory* ob = nullptr;
    if (ob == nullptr)
        ob = new OperationFactory;
    return ob;
}

OperationProxy* OperationFactory::createBinaryOperation(BinaryOperation::function_type op, const QString& notation) const {
    return new OperationProxy(new BinaryOperation(op, notation));
}

OperationProxy* OperationFactory::createUnaryOperation(UnaryOperation::function_type op, const QString& notation) const {
    return new OperationProxy(new UnaryOperation(op, notation));
}
