#include "OperationContainer.h"

OperationContainer::OperationContainer() {

}

OperationContainer::OperationContainer(const OperationContainer& operations) {
    for (const auto & it: operations)
        oper.insert(it->notation(), it->clone());
}

OperationContainer::OperationContainer(std::initializer_list<value_type>& list) {
    for (const auto & it: list)
        oper.insert(it->notation(), it->clone());
}

OperationContainer& OperationContainer::operator=(const OperationContainer& operations) {
    for (const auto & it: operations)
        oper.insert(it->notation(), it->clone());
    return *this;
}

auto OperationContainer::insert(value_type op) -> iterator {
    return oper.insert(op->notation(), op->clone());
}

auto OperationContainer::find(const key_type& str) -> iterator {
    return oper.find(str);
}

auto OperationContainer::toSortedList() const -> QList<value_type> {
    QList<value_type> list = createList();
    std::sort(list.begin(), list.end(), [](value_type op1, value_type op2) -> bool {
            return op1->notation().size() < op2->notation().size();
        });
    return list;
}

int OperationContainer::remove(const key_type& str) {
    return oper.remove(str);
}

bool OperationContainer::contains(const key_type& str) const {
    return oper.contains(str);
}

int OperationContainer::size() const {
    return oper.size();
}

bool OperationContainer::isEmpty() const {
    return oper.isEmpty();
}

auto OperationContainer::operator[](const key_type& s) const -> value_type {
    return oper[s];
}

auto OperationContainer::operator[](const key_type& s) -> value_type {
    return oper[s];
}

auto OperationContainer::begin() -> iterator {
    return oper.begin();
}

auto OperationContainer::begin() const -> const_iterator {
    return oper.begin();
}

auto OperationContainer::end() -> iterator {
    return oper.end();
}

auto OperationContainer::end() const -> const_iterator {
    return oper.end();
}

auto OperationContainer::cbegin() const -> const_iterator {
    return oper.cbegin();
}

auto OperationContainer::cend() const -> const_iterator {
    return oper.cend();
}

auto OperationContainer::createList() const -> QList<value_type> {
    QList<value_type> list;
    for (auto & x: oper)
        list.push_back(x);
    return list;
}
