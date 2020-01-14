
#include "ValidatorContainer.h"

#include "Validator.h"

ValidatorContainer::ValidatorContainer() { }

ValidatorContainer::ValidatorContainer(const ValidatorContainer& v) {
    copyContainer(v.validators);
}

void ValidatorContainer::copyContainer(const container_type& cont) {
    for (const auto & it: cont)
       validators.push_back(it->clone());
}

ValidatorContainer::ValidatorContainer(const std::initializer_list<value_type>& list) {
    for (const auto & it: list)
       validators.push_back(it->clone());
}

ValidatorContainer& ValidatorContainer::operator=(const ValidatorContainer& ob) {
    copyContainer(ob.validators);
    return *this;
}

auto ValidatorContainer::insert(value_type validator) -> iterator {
    return validators.insert(validators.end(), validator->clone());
}

auto ValidatorContainer::toList() const -> QList<value_type> {
    return validators;
}

int ValidatorContainer::remove(value_type v) {
    return validators.removeAll(v);
}

bool ValidatorContainer::contains(value_type v) const {
    return validators.contains(v);
}

int ValidatorContainer::size() const {
    return validators.size();
}

bool ValidatorContainer::isEmpty() const {
    return validators.isEmpty();
}

auto ValidatorContainer::begin() -> iterator {
    return validators.begin();
}

auto ValidatorContainer::begin() const -> const_iterator {
    return validators.begin();
}

auto ValidatorContainer::end() -> iterator {
    return validators.end();
}

auto ValidatorContainer::end() const -> const_iterator {
    return validators.end();
}

auto ValidatorContainer::cbegin() const -> const_iterator {
    return validators.cbegin();
}

auto ValidatorContainer::cend() const -> const_iterator {
    return validators.cend();
}
