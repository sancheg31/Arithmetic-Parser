#pragma once

#include <QVector>

#include "OperationContainer.h"
#include "UnaryOperation.h"
#include "BinaryOperation.h"

class OperationPrecedenceTable {
public:

    using value_type = OperationContainer::value_type;
    OperationPrecedenceTable();

    void insert(value_type, int);
    int remove(const QString&);

    bool contains(const QString&) const;
    bool isEmpty() const;
    int rowCount() const;
    int getOperationRow(const QString&) const;

    QPair<value_type, int> nearestOperation(const QString&, int pos, int priority) const;
    value_type currentOperation(const QString&, int pos, int priority) const;

    OperationContainer& operator[](int i) { return operations[i]; }
    const OperationContainer& operator[](int i) const { return operations[i]; }

private:

    void addAdditionalRows(int priority);
    void addRow();

    QVector<OperationContainer> operations;
};
