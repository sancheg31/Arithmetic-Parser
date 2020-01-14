#pragma once

#include "Validator.h"

class RegexValidator: public Validator
{
public:
    RegexValidator(const QRegExp& v): validator(v) { }
    RegexValidator(const RegexValidator& ob): validator(ob.validator) { }
    RegexValidator& operator=(const RegexValidator& ob) {
        validator = ob.validator;
        return *this;
    }
    virtual bool isValid(const Expression & expr) const override;

private:
    QRegExp validator;
};

