#pragma once

#include <QVector>

#include "OperationContainer.h"
#include "UnaryOperation.h"
#include "BinaryOperation.h"

class OperationTable {
public:
    OperationTable();

    void add(Operation*, size_t = 0);
    int remove(const QString&);

    bool contains(const QString&) const;
    bool isEmpty() const;
    int columnCount() const;
    int column(const QString&) const;

private:
    QVector<OperationContainer> binaryOperations;
    OperationContainer unaryOperations;
};
