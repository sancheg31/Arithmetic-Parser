#include "OperationProxy.h"

OperationProxy::OperationProxy(Operation* op): Operation(), operation(op) {

}

BinaryOperation* OperationProxy::tryCastToBinary() const {
    if (operation->type() == OperationType::BinaryOperation)
        return dynamic_cast<BinaryOperation*>(operation);
    return nullptr;
}

UnaryOperation* OperationProxy::tryCastToUnary() const {
    if (operation->type() == OperationType::UnaryOperation)
        return dynamic_cast<UnaryOperation*>(operation);
    return nullptr;
}

Operation* OperationProxy::clone() const {
    return operation->clone();
}
