#include "Operation.h"

Operation::Operation() { }

Operation::Operation(QString notation, OperationType type):
    operNotation(notation), operType(type) { }

Operation::~Operation() { }

Operation::OperationType Operation::type() const {
    return operType;
}



QString Operation::notation() const {
    return operNotation;
}
