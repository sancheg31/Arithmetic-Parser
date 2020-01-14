#pragma once

#include "ExpressionConverter.h"

#include <QVector>
#include <optional>
#include <QVariant>

using std::optional;
using std::make_optional;

class ExpressionToDoubleConverter: public ExpressionConverter
{
public:

    using conversion_function_type = std::function<double(const QString&)>;

    ExpressionToDoubleConverter() { }
    ExpressionToDoubleConverter(std::initializer_list<QRegExp> list) {
        for (auto x: list)
            expressionTypes.push_back(x);
    }
    ExpressionToDoubleConverter(const ExpressionToDoubleConverter& ob): expressionTypes(ob.expressionTypes) { }
    ExpressionToDoubleConverter& operator=(const ExpressionToDoubleConverter& ob) {
        expressionTypes = ob.expressionTypes; return *this;
    }

    virtual ~ExpressionToDoubleConverter() override { }

    virtual bool isValid(const QString & exprs) const override;
    virtual void addExpressionType(const QRegExp& reg) override;
    virtual void addExpressionType(const QString& str) override;
    optional<double> getValue(const QString& expr, conversion_function_type conv = defaultConverter) const;

    static optional<double> convert(const QString& expr, conversion_function_type conv = defaultConverter);

private:
    static const conversion_function_type defaultConverter;
    QVector<QRegExp> expressionTypes;
};

const ExpressionToDoubleConverter::conversion_function_type ExpressionToDoubleConverter::defaultConverter =
[](const QString& str) -> double {
    return str.toDouble();
};








