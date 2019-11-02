#pragma once

#include <QVector>

#include "OperationContainer.h"

class OperationTable: public QVector<OperationContainer> {
public:
    OperationTable();
};
