#include <QCoreApplication>
#include <QDebug>
#include <QtMath>

#include "Parser.h"
#include "Operation.h"
#include "UnaryOperation.h"
#include "OperationContainer.h"
#include "OperationTable.h"

OperationContainer createUnaryOperationsList() {
    OperationContainer result;
    result.insert(new UnaryOperation([](QVariant v) -> QVariant { return (v.isValid()) ? v.toDouble() : v; }, "+"));
    result.insert(new UnaryOperation([](QVariant v) -> QVariant { return (v.isValid()) ? -v.toDouble() : v; }, "-"));
    result.insert(new UnaryOperation([](QVariant v) -> QVariant { return (v.isValid()) ? v.toDouble()+1 : v; }, "++"));
    result.insert(new UnaryOperation([](QVariant v) -> QVariant { return (v.isValid()) ? v.toDouble()-1 : v; }, "--"));
    return result;
}

OperationContainer createBinaryOperationsList() {
    OperationContainer result;
    result.insert(new BinaryOperation([](QVariant a, QVariant b) -> QVariant {
                      return (a.isValid() && b.isValid()) ? a.toDouble() + b.toDouble() : QVariant{};
                  }, "+"));
    result.insert(new BinaryOperation([](QVariant a, QVariant b) -> QVariant {
                      return (a.isValid() && b.isValid()) ? a.toDouble() - b.toDouble() : QVariant{};
                  }, "-"));
    result.insert(new BinaryOperation([](QVariant a, QVariant b) -> QVariant {
                      return (a.isValid() && b.isValid()) ? a.toDouble() * b.toDouble() : QVariant{};
                  }, "*"));
    result.insert(new BinaryOperation([](QVariant a, QVariant b) -> QVariant {
                      return (a.isValid() && b.isValid()) ? a.toDouble() / b.toDouble() : QVariant{};
                  }, "/"));
    return result;
}

OperationTable createOperationTable() {
    OperationTable table;
    auto unaryOperations = createUnaryOperationsList();
    auto binaryOperations = createBinaryOperationsList();
    for (auto & op: unaryOperations)
        table.insert(op, 0);
    for (auto & op: binaryOperations) {
        if (op->notation() == "+" || op->notation() == "-")
            table.insert(op, 2);
        else if (op->notation() == "*" || op->notation() == "/")
            table.insert(op, 1);
    }
    return table;
}

int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);

    QString str = "=(++(++7)+(--6)*++12)";
    auto table = createOperationTable();
    Parser parser(table, QSet<QString>{});
    QVariant value = parser.parse(str);
    qDebug() << "result is: " << ((value.type() == QVariant::Invalid) ? QString("####") : value.toString());

    return a.exec();
}




