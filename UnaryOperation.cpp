#include "UnaryOperation.h"

UnaryOperation::UnaryOperation(std::function<QVariant(QVariant)> op, const QString & str):
    Operation(str, OperationType::UnaryOperation), operation(op) { }

UnaryOperation::UnaryOperation(const UnaryOperation & ob):
    Operation(ob.operNotation, ob.operType), operation(ob.operation) { }

UnaryOperation &UnaryOperation::operator=(const UnaryOperation & ob) {
    operation = ob.operation;
    operNotation = ob.operNotation;
    operType = ob.operType;
    return *this;
}

inline QVariant UnaryOperation::operator()(QVariant v) const {
    return operation(v);
}

UnaryOperation::~UnaryOperation() {}
