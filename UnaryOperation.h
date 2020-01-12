#pragma once

#include "Operation.h"

class UnaryOperation: public Operation
{
public:
    using function_type = std::function<QVariant(QVariant)>;

    UnaryOperation(function_type, const QString&);
    UnaryOperation(const UnaryOperation&);
    UnaryOperation& operator=(const UnaryOperation&);

    virtual ~UnaryOperation() override;

    virtual QVariant operator()(QVariant v) const;

private:
    function_type operation;
};
