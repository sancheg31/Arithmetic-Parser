#include "RegexValidator.h"

RegexValidator::RegexValidator(QRegExp expr): Validator(), expression(expr) { }

RegexValidator::RegexValidator(Validator* v): Validator(v) { }

RegexValidator::RegexValidator(const std::initializer_list<Validator *> &list): Validator(list) { }

RegexValidator::RegexValidator(const RegexValidator &ob): Validator(ob.children), expression(ob.expression) { }

RegexValidator &RegexValidator::operator=(const RegexValidator& ob) {
    children = ob.children;
    return *this;
}

bool RegexValidator::isValid(const Expression &expr) const {
    if (expression.exactMatch(expr) && areChildrenValid(expr))
        return true;
    return false;
}

Validator *RegexValidator::clone() const {
    return new RegexValidator(expression, children);
}

RegexValidator::RegexValidator(QRegExp expr, const ValidatorContainer& cont): Validator(cont), expression(expr) { }






