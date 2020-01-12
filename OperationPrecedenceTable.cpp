#include <QDebug>

#include "OperationPrecedenceTable.h"

OperationPrecedenceTable::OperationPrecedenceTable() {
    addRow();
}

void OperationPrecedenceTable::insert(Operation* op, int priority) {
    if (priority >= operations.size()) {
        addAdditionalRows(priority);
    }
    operations[priority].insert(op);
}

void OperationPrecedenceTable::addAdditionalRows(int priority) {
    while (operations.size() <= priority)
        addRow();
}

void OperationPrecedenceTable::addRow() {
    operations.push_back(OperationContainer{});
}

int OperationPrecedenceTable::remove(const QString& str) {
    for (auto & x : operations) {
        int c = x.remove(str);
        if (c)
            return c;
    }
    return 0;
}

Operation* OperationPrecedenceTable::currentOperation(const QString & str, int pos, int priority) const {
    auto list = operations[priority].toSortedList();
    for (auto it = list.rbegin(); it != list.rend(); ++it) {
        int curIndex = str.indexOf((*it)->notation(), pos);
        if (curIndex == pos)
            return (*it);
    }
    return nullptr;
}



QPair<Operation*, int> OperationPrecedenceTable::nearestOperation(const QString & str, int pos, int priority) const {
    auto list = operations[priority].toSortedList();
    int minIndex = str.size();
    Operation* result = nullptr;
    for (int i = list.size()-1; i > -1; --i) {
        int curIndex = str.indexOf(list[i]->notation(), pos);
        if (curIndex < minIndex && curIndex != -1) {
            minIndex = curIndex;
            result = list[i];
        }
    }
    return QPair{result, minIndex};
}

bool OperationPrecedenceTable::contains(const QString& str) const {
    for (auto & x: operations)
        if (x.contains(str))
            return true;
    return false;
}

bool OperationPrecedenceTable::isEmpty() const {
    return operations.isEmpty();
}
int OperationPrecedenceTable::rowCount() const {
    return operations.size();
}

int OperationPrecedenceTable::getOperationRow(const QString & str) const {
    for (int i = 0; i < operations.size(); ++i)
        if (operations[i].contains(str))
            return i;
    return -1;
}





