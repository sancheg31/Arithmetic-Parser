#pragma once

#include "Validator.h"
#include "ValidatorContainer.h"

class RegexValidator: public Validator
{
public:
    RegexValidator() { }
    explicit RegexValidator(QRegExp expr);
    explicit RegexValidator(Validator* v);
    RegexValidator(const std::initializer_list<Validator*>& list);
    RegexValidator(const RegexValidator& ob);
    RegexValidator& operator=(const RegexValidator& ob);

    virtual bool isValid(const Expression& expr) const override;
    virtual Validator* clone() const override;

protected:
    RegexValidator(QRegExp expr, const ValidatorContainer& cont);
private:
    QRegExp expression;
};

