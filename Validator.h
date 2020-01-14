#pragma once

#include <QString>
#include <QRegExp>
#include <QVariant>

#include "Expression.h"

class Validator
{
public:
    virtual bool isValid(const Expression&) const = 0;

    virtual void addValidator(Validator* v) = 0;
    virtual int removeValidator(Validator* v) = 0;

    virtual Validator* clone() const = 0;

    virtual ~Validator() { }
};

