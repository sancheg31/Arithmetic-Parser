#include "IOperation.h"

IOperation::~IOperation() {}

IOperation::OperationType IOperation::type() const {
    return operType;
}

QString IOperation::notation() const {
    return operNotation;
}
