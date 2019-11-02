#pragma once

#include <QSet>
#include <QHash>
#include <initializer_list>
#include <type_traits>

#include "Operation.h"

class OperationContainer {
public:

    using iterator = QHash<QString, Operation*>::iterator;
    using const_iterator = QHash<QString, Operation*>::const_iterator;

    OperationContainer();
    OperationContainer(const OperationContainer&);
    OperationContainer(std::initializer_list<Operation*>& list);

    template <typename ... Tp>
    OperationContainer(std::enable_if<std::conjunction_v<std::is_same_v<Tp, Operation*>...>, Tp> ... tp);

    iterator insert(Operation*);
    int remove(Operation*);
    iterator find(Operation*);

    bool contains(Operation*) const;
    int size() const;
    bool isEmpty() const;

    iterator begin() { return oper.begin(); }
    const_iterator begin() const { return oper.begin(); }
    iterator end() { return oper.end(); }
    const_iterator end() const { return oper.end(); }

    const_iterator cbegin() const { return oper.cbegin(); }
    const_iterator cend() const { return oper.cend(); }

private:
    QHash<QString, Operation*> oper;
};
