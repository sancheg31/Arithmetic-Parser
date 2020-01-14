#pragma once

#include <QString>
#include <QRegExp>
#include <QVariant>

class ExpressionConverter
{
public:
    virtual bool isValid(const QString&) const = 0;

    virtual void addExpressionType(const QRegExp&) = 0;
    virtual void addExpressionType(const QString&) = 0;

    virtual ~ExpressionConverter();
};

