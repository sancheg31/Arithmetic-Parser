#include "Operation.h"

Operation::~Operation() {}

Operation::OperationType Operation::type() const {
    return operType;
}

QString Operation::notation() const {
    return operNotation;
}
