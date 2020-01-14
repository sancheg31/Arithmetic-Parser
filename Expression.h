#pragma once

#include <QString>

class Expression
{
public:
    virtual QString toString() const {
        return expression;
    }

private:
    QString expression;
};

