#pragma once

#include <functional>

#include "IOperation.h"

class BinaryOperation: public IOperation {
public:
    using binary_function_type = std::function<QVariant(QVariant, QVariant)>;

    BinaryOperation(binary_function_type, const QString&);
    BinaryOperation(const BinaryOperation&);
    BinaryOperation& operator=(const BinaryOperation&);

    virtual ~BinaryOperation() override;
    virtual QVariant operator()(QVariant v1, QVariant v2) const { return operation(v1, v2); }

private:
    binary_function_type operation;
};
