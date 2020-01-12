#pragma once

#include <QSet>
#include <QHash>
#include <initializer_list>
#include <type_traits>

#include "OperationProxy.h"

class OperationContainer
{
public:

    using value_type = OperationProxy*;
    using iterator = QHash<QString, value_type>::iterator;
    using const_iterator = QHash<QString, value_type>::const_iterator;


    OperationContainer();
    OperationContainer(const OperationContainer&);
    OperationContainer(std::initializer_list<value_type>& list);

    OperationContainer& operator=(const OperationContainer&);

    iterator insert(value_type);
    int remove(const QString&);
    iterator find(const QString&);

    QList<value_type> toSortedList() const;
    bool contains(const QString&) const;
    int size() const;
    bool isEmpty() const;

    value_type const operator[](const QString&) const;
    value_type operator[](const QString&);

    iterator begin();
    const_iterator begin() const;
    iterator end();
    const_iterator end() const;

    const_iterator cbegin() const;
    const_iterator cend() const;

private:
    QList<value_type> createList() const;
    QHash<QString, value_type> oper;
};


