#include "OperationContainer.h"

OperationContainer::OperationContainer() {

}

OperationContainer::OperationContainer(const OperationContainer& operations) {
    for (const auto & it: operations)
        oper.insert(it->notation(), it);
}

OperationContainer::OperationContainer(std::initializer_list<Operation*> & list) {
    for (const auto & it: list)
        oper.insert(it->notation(), it);
}

template <typename ... Tp>
OperationContainer::OperationContainer(std::enable_if<std::conjunction_v<std::is_base_of<Operation*, Tp>()...>, Tp> ... tp) {
    ((insert(tp->operation(), tp)), ...);
}

auto OperationContainer::insert(Operation* op) -> iterator {
    return oper.insert(op->notation(), op);
}

auto OperationContainer::find(const QString& str) -> iterator {
    return oper.find(str);
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
