#pragma once

#include <QSet>
#include <QHash>
#include <initializer_list>
#include <type_traits>

#include "OperationProxy.h"

class OperationContainer
{
protected:
    using container_type = QHash<QString, OperationProxy*>;

private:
    using key_type = QString;
    using mapped_type = OperationProxy*;

public:

    using value_type = mapped_type;
    using iterator = container_type::iterator;
    using const_iterator = container_type::const_iterator;


    OperationContainer();
    OperationContainer(const OperationContainer&);
    OperationContainer(std::initializer_list<value_type>& list);
    OperationContainer& operator=(const OperationContainer&);

    iterator insert(value_type);
    int remove(const key_type&);
    iterator find(const key_type&);

    QList<value_type> toSortedList() const;
    bool contains(const key_type&) const;
    int size() const;
    bool isEmpty() const;

    value_type operator[](const key_type&) const;
    value_type operator[](const key_type&);

    iterator begin();
    const_iterator begin() const;
    iterator end();
    const_iterator end() const;

    const_iterator cbegin() const;
    const_iterator cend() const;

private:
    QList<value_type> createList() const;
    container_type oper;
};


