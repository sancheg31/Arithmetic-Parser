#include <QDebug>

#include "OperationTable.h"

OperationTable::OperationTable() {
    operations.push_back(OperationContainer{});
}

void OperationTable::add(Operation* op, int priority) {

    if (priority == 0 && op->type() == Operation::OperationType::UnaryOperation) {
        operations[0].insert(dynamic_cast<UnaryOperation*>(op));
    }
    else if (op->type() == Operation::OperationType::BinaryOperation) {
        if (priority > 0 && priority < operations.size()) {
            operations[priority].insert(dynamic_cast<BinaryOperation*>(op));
        }
        else if (priority >= operations.size()) {
            operations.push_back(OperationContainer{});
            operations[operations.size()-1].insert(dynamic_cast<BinaryOperation*>(op));
        }

    }
}

int OperationTable::remove(const QString& str) {
    for (auto & x : operations) {
        int c = x.remove(str);
        if (c)
            return c;
    }
    return 0;
}

bool OperationTable::contains(const QString& str) const {
    for (auto & x: operations)
        if (x.contains(str))
            return true;
    return false;
}

bool OperationTable::isEmpty() const {
    return operations.isEmpty();
}
int OperationTable::columnCount() const {
    return operations.size();
}

int OperationTable::column(const QString& str) const {
    for (int i = 0; i < operations.size(); ++i)
        if (operations[i].contains(str))
            return i;
    return -1;
}





