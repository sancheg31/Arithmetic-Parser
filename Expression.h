#pragma once

#include <QString>

class Expression
{
public:
    explicit Expression(const QString& str): expression(str) { }
    virtual QString toString() const {
        return expression;
    }

private:
    QString expression;
};

