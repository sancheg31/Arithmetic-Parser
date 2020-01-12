#pragma once

#include <QSet>
#include <QHash>
#include <initializer_list>
#include <type_traits>

#include "OperationProxy.h"

class OperationContainer
{
public:

    using iterator = QHash<QString, OperationProxy*>::iterator;
    using const_iterator = QHash<QString, OperationProxy*>::const_iterator;

    OperationContainer();
    OperationContainer(const OperationContainer&);
    OperationContainer(std::initializer_list<OperationProxy*>& list);

    OperationContainer& operator=(const OperationContainer&);

    iterator insert(OperationProxy*);
    int remove(const QString&);
    iterator find(const QString&);

    QList<OperationProxy*> toSortedList() const;
    bool contains(const QString&) const;
    int size() const;
    bool isEmpty() const;

    const OperationProxy* operator[](const QString&) const;
    OperationProxy* operator[](const QString&);

    iterator begin();
    const_iterator begin() const;
    iterator end();
    const_iterator end() const;

    const_iterator cbegin() const;
    const_iterator cend() const;

private:
    QList<OperationProxy*> createList() const;
    QHash<QString, OperationProxy*> oper;
};


