#include "RegexValidator.h"

RegexValidator::RegexValidator(QRegExp expr): expression(expr) { }

RegexValidator::RegexValidator(Validator* v) { validators.insert(v); }

RegexValidator::RegexValidator(std::initializer_list<Validator *> &list) {
    validators = ValidatorContainer(list);
}

RegexValidator::RegexValidator(const RegexValidator &ob) {
    validators = ValidatorContainer(ob.validators);
}

RegexValidator &RegexValidator::operator=(const RegexValidator& ob) {
    validators = ob.validators;
    return *this;
}

bool RegexValidator::isValid(const Expression &expr) const {
    if (expression.exactMatch(expr) && matchesChildren(expr))
        return true;
    return false;
}

bool RegexValidator::matchesChildren(const Expression &expr) const {
    for (auto & val: validators)
        if (!val->isValid(expr))
            return false;
    return true;
}

Validator *RegexValidator::clone() const {
    return new RegexValidator(validators);
}

RegexValidator::RegexValidator(const ValidatorContainer& ob) {
    for (Validator* val: ob)
        validators.insert(val->clone());
}






