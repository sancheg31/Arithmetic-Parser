#pragma once

#include <QString>
#include <QRegExp>
#include <QVariant>

#include "Expression.h"
#include "ValidatorContainer.h"

class Validator
{
public:
    virtual bool isValid(const Expression&) const = 0;

    virtual void addValidator(Validator *v) {
        validators.insert(v);
    }

    virtual int removeValidator(Validator *v) {
        return validators.remove(v);
    }

    virtual Validator* clone() const = 0;

    virtual ~Validator() { }
protected:
    ValidatorContainer validators;
};

