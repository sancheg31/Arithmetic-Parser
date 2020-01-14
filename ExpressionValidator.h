#pragma once

#include <QString>
#include <QRegExp>
#include <QVariant>

class Validator;
class ValidatorContainer;
class Expression;

class ExpressionValidator
{
public:

    virtual bool isValid(const Expression&) const = 0;
    virtual ~ExpressionValidator();

};

