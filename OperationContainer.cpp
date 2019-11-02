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
OperationContainer::OperationContainer(std::enable_if<std::conjunction_v<std::is_same_v<Tp, Operation*>...>, Tp> ... tp) {
    ((insert(tp->operation(), tp)), ...);
}

auto OperationContainer::insert(Operation* op) -> iterator {
    return oper.insert(op->notation(), op);
}

auto OperationContainer::find(Operation* op) -> iterator {
    return oper.find(op->notation());
}

int OperationContainer::remove(Operation* op) {
    return oper.remove(op->notation());
}


bool OperationContainer::contains(Operation* op) const {
    return oper.contains(op->notation());
}

int OperationContainer::size() const {
    return oper.size();
}

bool OperationContainer::isEmpty() const {
    return oper.isEmpty();
}
