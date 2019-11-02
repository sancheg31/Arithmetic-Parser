#include "OperationTable.h"

OperationTable::OperationTable() {

}

void OperationTable::add(Operation* op, size_t priority) {
    if (op->type() == Operation::OperationType::UnaryOperation) {
        if (priority == 0) {
            op = dynamic_cast<UnaryOperation*>(op);
            operations[0].insert(op);
        }
    } else {
        op = dynamic_cast<BinaryOperation*>(op);
        if (priority < operations.size() && priority != 0) {
            operations[priority].insert(op);
        }
        else if (priority != 0 && priority >= operations.size()) {
            OperationContainer cont;
            cont.insert(op);
            operations.push_back(cont);
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





