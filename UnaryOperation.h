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
    virtual UnaryOperation* clone() const override;

private:
    function_type operation;
};
