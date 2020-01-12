#include "OperationProxy.h"

OperationProxy::OperationProxy(Operation* op): Operation(), operation(op) {

}

BinaryOperation* OperationProxy::tryCastToBinary() const {
    if (operation->type() == OperationType::BinaryOperation)
        return dynamic_cast<BinaryOperation*>(operation->clone());
    return nullptr;
}

UnaryOperation* OperationProxy::tryCastToUnary() const {
    if (operation->type() == OperationType::UnaryOperation)
        return dynamic_cast<UnaryOperation*>(operation->clone());
    return nullptr;
}

Operation::OperationType OperationProxy::type() const {
    return operation->type();
}

QString OperationProxy::notation() const {
    return operation->notation();
}

Operation* OperationProxy::clone() const {
    return operation->clone();
}
