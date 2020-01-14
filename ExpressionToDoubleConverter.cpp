#include "ExpressionToDoubleConverter.h"



bool ExpressionToDoubleConverter::isValid(const QString & expr) const {
    for (const auto & el: expressionTypes)
        if (el.exactMatch(expr))
            return true;
    return false;
}

void ExpressionToDoubleConverter::addExpressionType(const QRegExp & reg) {
    expressionTypes.push_back(reg);
}

void ExpressionToDoubleConverter::addExpressionType(const QString& str) {
    expressionTypes.push_back(QRegExp(str));
}

optional<double> ExpressionToDoubleConverter::getValue(const QString &expr, conversion_function_type conv) const {
    if (isValid(expr)) {
        double result = conv(expr);
        return make_optional<double>(result);
    }
    return {};
}


optional<double> ExpressionToDoubleConverter::convert(const QString& expr, conversion_function_type conv) {

}
