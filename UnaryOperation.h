#pragma once

#include "Operation.h"

class UnaryOperation: Operation {

    virtual ~UnaryOperation();
    virtual QVariant operator()(QVariant) const = 0;
    virtual OperationType type() const { return OperationType::UnaryOperation; }
};
