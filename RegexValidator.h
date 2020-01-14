#pragma once

#include "Validator.h"
#include "ValidatorContainer.h"

class RegexValidator: public Validator
{
public:
    RegexValidator() { }
    explicit RegexValidator(QRegExp expr);
    explicit RegexValidator(Validator* v);
    RegexValidator(std::initializer_list<Validator*>& list);
    RegexValidator(const RegexValidator& ob);
    RegexValidator& operator=(const RegexValidator& ob);

    virtual bool isValid(const Expression& expr) const override;
    virtual Validator* clone() const override;

protected:
    RegexValidator(const ValidatorContainer&);
private:
    bool matchesChildren(const Expression& expr) const;
    QRegExp expression;
};

