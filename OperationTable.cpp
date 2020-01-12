#include <QDebug>

#include "OperationTable.h"

OperationTable::OperationTable() {
    addRow();
}

void OperationTable::insert(IOperation* op, int priority) {
    if (priority >= operations.size()) {
        addAdditionalRows(priority);
    }
    operations[priority].insert(op);
}

void OperationTable::addAdditionalRows(int priority) {
    while (operations.size() <= priority)
        addRow();
}

void OperationTable::addRow() {
    operations.push_back(OperationContainer{});
}

int OperationTable::remove(const QString& str) {
    for (auto & x : operations) {
        int c = x.remove(str);
        if (c)
            return c;
    }
    return 0;
}

IOperation* OperationTable::currentOperation(const QString & str, int pos, int priority) const {
    auto list = operations[priority].toSortedList();
    for (auto it = list.rbegin(); it != list.rend(); ++it) {
        int curIndex = str.indexOf((*it)->notation(), pos);
        if (curIndex == pos)
            return (*it);
    }
    return nullptr;
}



QPair<IOperation*, int> OperationTable::nearestOperation(const QString & str, int pos, int priority) const {
    auto list = operations[priority].toSortedList();
    int minIndex = str.size();
    IOperation* result = nullptr;
    for (int i = list.size()-1; i > -1; --i) {
        int curIndex = str.indexOf(list[i]->notation(), pos);
        if (curIndex < minIndex && curIndex != -1) {
            minIndex = curIndex;
            result = list[i];
        }
    }
    return QPair{result, minIndex};
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
int OperationTable::rowCount() const {
    return operations.size();
}

int OperationTable::getOperationRow(const QString &) const& str) const {
    for (int i = 0; i < operations.size(); ++i)
        if (operations[i].contains(str))
            return i;
    return -1;
}





