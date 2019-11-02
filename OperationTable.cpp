#include "OperationTable.h"

OperationTable::OperationTable() {

}

void OperationTable::add(Operation* op, size_t priority) {
    if (op->type() == Operation::OperationType::UnaryOperation) {
        op = dynamic_cast<UnaryOperation*>(op);
        unaryOperations.insert(op);
    } else {
        op = dynamic_cast<BinaryOperation*>(op);
        if (priority <= binaryOperations.size()) {
            binaryOperations[priority-1].insert(op);
        }
        else {
            OperationContainer cont;
            cont.insert(op);
            binaryOperations.push_back(cont);
        }
    }
}

int OperationTable::remove(const QString& str) {
    int count = unaryOperations.remove(str);
    if (count)
        return count;
    for (auto & x : binaryOperations) {
        int c = x.remove(str);
        if (c)
            return c;
    }
    return 0;
}

bool OperationTable::contains(const QString& str) const {
    if (unaryOperations.contains(str))
        return true;
    for (auto & x: binaryOperations)
        if (x.contains(str))
            return true;
    return false;
}

bool OperationTable::isEmpty() const {
    return unaryOperations.isEmpty() && binaryOperations.isEmpty();
}
int OperationTable::columnCount() const {
    return binaryOperations.size() + 1;
}

int OperationTable::column(const QString& str) const {
    if (unaryOperations.contains(str))
        return 0;
    for (int i = 0; i < binaryOperations.size(); ++i)
        if (binaryOperations[i].contains(str))
            return i+1;
    return -1;
}





