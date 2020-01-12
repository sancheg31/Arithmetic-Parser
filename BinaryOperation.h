#pragma once

#include <functional>

#include "Operation.h"

class BinaryOperation: public Operation
{
public:
    using function_type = std::function<QVariant(QVariant, QVariant)>;

    BinaryOperation(function_type, const QString&);
    BinaryOperation(const BinaryOperation&);
    BinaryOperation& operator=(const BinaryOperation&);

    virtual ~BinaryOperation() override;

    virtual QVariant operator()(QVariant v1, QVariant v2) const;
    virtual BinaryOperation* clone() const override;
private:
    function_type operation;
};
