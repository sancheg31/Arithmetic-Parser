#pragma once

#include <QVector>

#include "OperationContainer.h"
#include "UnaryOperation.h"
#include "BinaryOperation.h"

class OperationTable {
public:

    using value_type = OperationContainer;
    OperationTable();

    void insert(IOperation*, int);
    int remove(const QString&);

    bool contains(const QString&) const;
    bool isEmpty() const;
    int rowCount() const;
    int getOperationRow(const QString&) const;

    QPair<IOperation*, int> nearestOperation(const QString&, int pos, int priority) const;
    IOperation* currentOperation(const QString&, int pos, int priority) const;

    OperationContainer& operator[](int i) { return operations[i]; }
    const OperationContainer& operator[](int i) const { return operations[i]; }
private:

    void insertUnaryOperation(IOperation*);
    void insertBinaryOperation(IOperation*, int priority);

    void addAdditionalRows(int priority);
    void addRow();

    QVector<OperationContainer> operations;
};
