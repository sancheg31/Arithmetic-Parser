#pragma once

#include <QVector>

#include "Validator.h"

class ValidatorContainer
{
public:
    using value_type = Validator;
    using iterator = QVector<Validator*>::iterator;
    using const_iterator = QVector<Validator*>::const_iterator;

    ValidatorContainer();
    ValidatorContainer(const ValidatorContainer&);
    ValidatorContainer(std::initializer_list<value_type>& list);
    ValidatorContainer& operator=(const ValidatorContainer&);


};

