#include "BinaryOperation.h"


BinaryOperation::BinaryOperation(binary_function_type op, const QString & str):
    IOperation(str, OperationType::BinaryOperation), operation(op) { }

BinaryOperation::BinaryOperation(const BinaryOperation & ob): IOperation(ob.operNotation, ob.operType) {
    operation = ob.operation;
}

BinaryOperation &BinaryOperation::operator=(const BinaryOperation & ob) {
    operation = ob.operation;
    operNotation = ob.operNotation;
    return *this;
}

BinaryOperation::~BinaryOperation() { }
