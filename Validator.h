#pragma once

#include <QString>
#include <QRegExp>
#include <QVariant>

#include "Expression.h"
#include "ValidatorContainer.h"

class Validator
{
public:
    Validator() { }
    explicit Validator(Validator* v);
    Validator(const std::initializer_list<Validator*>& list);
    Validator(const Validator& ob);
    Validator& operator=(const Validator& ob);

    virtual bool isValid(const Expression&) const;
    virtual void addValidator(Validator *v);
    virtual int removeValidator(Validator *v);

    virtual Validator* clone() const;

    virtual ~Validator();
protected:
    virtual bool areChildrenValid(const Expression& expr) const;
    Validator(const ValidatorContainer&);
    ValidatorContainer children;
};

