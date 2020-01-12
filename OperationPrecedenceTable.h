#pragma once

#include <QVector>

#include "OperationContainer.h"
#include "UnaryOperation.h"
#include "BinaryOperation.h"

class OperationPrecedenceTable {
public:

    using value_type = OperationContainer;
    OperationPrecedenceTable();

    void insert(Operation*, int);
    int remove(const QString&);

    bool contains(const QString&) const;
    bool isEmpty() const;
    int rowCount() const;
    int getOperationRow(const QString&) const;

    QPair<Operation*, int> nearestOperation(const QString&, int pos, int priority) const;
    Operation* currentOperation(const QString&, int pos, int priority) const;

    OperationContainer& operator[](int i) { return operations[i]; }
    const OperationContainer& operator[](int i) const { return operations[i]; }

private:

    void addAdditionalRows(int priority);
    void addRow();

    QVector<OperationContainer> operations;
};
