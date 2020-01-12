#include "BinaryOperation.h"


BinaryOperation::BinaryOperation(function_type op, const QString & str):
    Operation(str, OperationType::BinaryOperation), operation(op) { }

BinaryOperation::BinaryOperation(const BinaryOperation & ob):
    Operation(ob.operNotation, ob.operType), operation(ob.operation) { }

BinaryOperation &BinaryOperation::operator=(const BinaryOperation & ob) {
    operation = ob.operation;
    operNotation = ob.operNotation;
    operType = ob.operType;
    return *this;
}

inline QVariant BinaryOperation::operator()(QVariant v1, QVariant v2) const {
    return operation(v1, v2);
}

BinaryOperation* BinaryOperation::clone() const {
    return new BinaryOperation(operation, operNotation);
}

BinaryOperation::~BinaryOperation() { }
