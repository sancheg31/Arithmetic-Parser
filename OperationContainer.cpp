#include "OperationContainer.h"

OperationContainer::OperationContainer() {

}

OperationContainer::OperationContainer(const OperationContainer& operations) {
    for (const auto & it: operations)
        oper.insert(it->notation(), it);
}

OperationContainer::OperationContainer(std::initializer_list<OperationProxy*> & list) {
    for (const auto & it: list)
        oper.insert(it->notation(), it);
}

OperationContainer& OperationContainer::operator=(const OperationContainer & operations) {
    for (const auto & it: operations)
        oper.insert(it->notation(), it);
    return *this;
}

auto OperationContainer::insert(OperationProxy* op) -> iterator {
    return oper.insert(op->notation(), op);
}

auto OperationContainer::find(const QString& str) -> iterator {
    return oper.find(str);
}

QList<OperationProxy*> OperationContainer::toSortedList() const {
    QList<OperationProxy*> list = createList();
    std::sort(list.begin(), list.end(), [](OperationProxy* op1, OperationProxy* op2) -> bool {
            return op1->notation().size() < op2->notation().size();
        });
    return list;
}

int OperationContainer::remove(const QString& str) {
    return oper.remove(str);
}

bool OperationContainer::contains(const QString& str) const {
    return oper.contains(str);
}

int OperationContainer::size() const {
    return oper.size();
}

bool OperationContainer::isEmpty() const {
    return oper.isEmpty();
}

const OperationProxy *OperationContainer::operator[](const QString& s) const {
    return oper[s];
}

OperationProxy *OperationContainer::operator[](const QString& s) {
    return oper[s];
}

OperationContainer::iterator OperationContainer::begin() {
    return oper.begin();
}

OperationContainer::const_iterator OperationContainer::begin() const {
    return oper.begin();
}

OperationContainer::iterator OperationContainer::end() {
    return oper.end();
}

OperationContainer::const_iterator OperationContainer::end() const {
    return oper.end();
}

OperationContainer::const_iterator OperationContainer::cbegin() const {
    return oper.cbegin();
}

OperationContainer::const_iterator OperationContainer::cend() const {
    return oper.cend();
}

QList<OperationProxy*> OperationContainer::createList() const {
    QList<OperationProxy*> list;
    for (auto & x: oper)
        list.push_back(x);
    return list;
}
