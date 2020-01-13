#pragma once

#include <QString>
#include <QVariant>
#include <QRegExp>

class LiteralExpression
{
public:
    virtual bool isValid(const QString&) const = 0;
    virtual QVariant value(const QString&) const = 0;
    virtual void addExpressionType(const QRegExp&) const = 0;
    virtual void addExpressionType(const QString&) const = 0;
    virtual void setExpression(const QString&) const = 0;
    virtual ~LiteralExpression();
};

