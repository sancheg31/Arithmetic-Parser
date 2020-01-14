#pragma once

#include "Validator.h"

#include "ValidatorContainer.h"

class RegexValidator: public Validator
{
public:
    RegexValidator();
    explicit RegexValidator(Validator* v);
    RegexValidator(std::initializer_list<Validator*>& list);
    RegexValidator(const RegexValidator& ob);
    RegexValidator& operator=(const RegexValidator& ob);

    virtual bool isValid(const Expression& expr) const override;

    virtual void addValidator(Validator* validator) override;
    virtual Validator* removeValidator(Validator* validator) override;

    virtual Validator* clone() const override;

protected:
    RegexValidator(const ValidatorContainer&);
private:
    ValidatorContainer validators;
};

