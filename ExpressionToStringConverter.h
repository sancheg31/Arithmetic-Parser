#pragma once

#include "ExpressionConverter.h"

#include <optional>
#include <QRegExp>
#include <QVector>

class ExpressionToStringConverter: public ExpressionConverter
{
public:
    ExpressionToStringConverter();
    ExpressionToStringConverter(std::initializer_list<QRegExp>);
    ExpressionToStringConverter(const ExpressionToStringConverter&);
    ExpressionToStringConverter& operator=(const ExpressionToStringConverter&);

    virtual ~ExpressionToStringConverter() override;
    virtual void addExpressionType(const QRegExp&) override;
    virtual void addExpressionType(const QString &)  override;

    static std::optional<double> getValue(ExpressionConverter* expr);


private:
    QVector<QRegExp> expressionTypes;
};

