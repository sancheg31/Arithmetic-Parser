#include "RegexValidator.h"

RegexValidator::RegexValidator(QRegExp expr): expression(expr) { }

RegexValidator::RegexValidator(Validator* v) { validators.insert(v); }

RegexValidator::RegexValidator(std::initializer_list<Validator *> &list): validators(list) { }

RegexValidator::RegexValidator(const RegexValidator &ob): validators(ob.validators) { }

RegexValidator &RegexValidator::operator=(const RegexValidator& ob) {
    validators = ob.validators;
    return *this;
}

bool RegexValidator::isValid(const Expression &expr) const {
    return true;
}

Validator *RegexValidator::clone() const {
    return new RegexValidator(validators);
}

void RegexValidator::addValidator(Validator *v) {
    validators.insert(v);
}

int RegexValidator::removeValidator(Validator *v) {
    return validators.remove(v);
}

RegexValidator::RegexValidator(const ValidatorContainer& ob) {
    for (Validator* val: ob)
        validators.insert(val->clone());
}
