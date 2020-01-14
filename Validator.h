#pragma once

#include <QString>
#include <QRegExp>
#include <QVariant>

class Validator;
class ValidatorContainer;
class Expression;

class Validator
{
public:
    virtual bool isValid(const Expression&) const = 0;

    virtual void addValidator(Validator*) = 0;
    virtual Validator* removeValidator(Validator*) = 0;

    virtual Validator* clone() const = 0;

    virtual ~Validator() { }
};

