#include "Validator.h"

Validator::Validator(Validator *v) {
    children.insert(v);
}

Validator::Validator(const std::initializer_list<Validator *> &list) {
    for (auto & v: list)
        children.insert(v);
}

Validator::Validator(const Validator &ob): children(ob.children) { }

Validator &Validator::operator=(const Validator &ob) {
    children = ob.children; return *this;
}

bool Validator::isValid(const Expression & expr) const {
    return areChildrenValid(expr);
}

void Validator::addValidator(Validator *v) {
    children.insert(v);
}

int Validator::removeValidator(Validator *v) {
    return children.remove(v);
}

Validator *Validator::clone() const {
    return new Validator(children);
}

bool Validator::areChildrenValid(const Expression &expr) const {
    for (auto & val: children)
        if (!val->isValid(expr))
            return false;
    return true;
}

Validator::Validator(const ValidatorContainer & cont) {
    for (Validator* val: cont)
        children.insert(val->clone());
}

Validator::~Validator() { }
