#pragma once

#include <QVector>

class Validator;

class ValidatorContainer
{
protected:
    using container_type = QList<Validator*>;

public:
    using value_type = Validator*;
    using iterator = container_type::iterator;
    using const_iterator = container_type::const_iterator;

    ValidatorContainer();
    ValidatorContainer(const ValidatorContainer&);
    ValidatorContainer(const std::initializer_list<value_type>& list);
    ValidatorContainer& operator=(const ValidatorContainer&);

    iterator insert(value_type);
    int remove(value_type);

    QList<value_type> toList() const;
    bool contains(value_type) const;
    int size() const;
    bool isEmpty() const;

    iterator begin();
    const_iterator begin() const;
    iterator end();
    const_iterator end() const;

    const_iterator cbegin() const;
    const_iterator cend() const;

private:
    void copyContainer(const container_type& cont);
    container_type validators;

};

