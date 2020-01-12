#include <QCoreApplication>
#include <QDebug>
#include <QtMath>

#include "Parser.h"
#include "IOperation.h"
#include "UnaryOperation.h"
#include "OperationContainer.h"
#include "OperationTable.h"

OperationContainer createUnaryOperationsList() {
    OperationContainer result;
    result.insert(new UnaryOperation([](QVariant v) { return (v.isValid()) ? v.toDouble() : v; }, "+"));
    result.insert(new UnaryOperation([](QVariant v) { return (v.isValid()) ? -v.toDouble(): v; }, "-"));
    result.insert(new UnaryOperation([](QVariant v) { return (v.isValid()) ? v.toDouble()+1: v; }, "++"));
    result.insert(new UnaryOperation([](QVariant v) { return (v.isValid()) ? v.toDouble()-1: v; }, "--"));
    return result;
}

OperationContainer createBinaryOperationsList() {
    OperationContainer result;
    result.insert(new BinaryOperation([](QVariant a, QVariant b) {
                      return (a.isValid() && b.isValid()) ? a.toDouble() + b.toDouble() : QVariant::Invalid;
                  }, "+"));
    result.insert(new BinaryOperation([](QVariant a, QVariant b) {
                      return (a.isValid() && b.isValid()) ? a.toDouble() + b.toDouble() : QVariant::Invalid;
                  }, "-"));
    result.insert(new BinaryOperation([](QVariant a, QVariant b) {
                      return (a.isValid() && b.isValid()) ? a.toDouble() + b.toDouble() : QVariant::Invalid;
                  }, "*"));
    result.insert(new BinaryOperation([](QVariant a, QVariant b) {
                      return (a.isValid() && b.isValid()) ? a.toDouble() + b.toDouble() : QVariant::Invalid;
                  }, "/"));
    return result;
}

OperationTable createOperationTable() {
    OperationTable table;
    auto unaryOperations = createUnaryOperationsList();
    auto binaryOperations = createBinaryOperationsList();
    table.add(new UnaryOperation([](QVariant v) -> QVariant {
                  return (v.type() == QVariant::Invalid) ? v : v.toDouble();
              }, "+"), 0);
    table.add(new UnaryOperation([](QVariant v) -> QVariant {
                  return (v.type() == QVariant::Invalid) ? v : -v.toDouble();
              }, "-"), 0);
    table.add(new UnaryOperation([](QVariant v) -> QVariant {
                  return (v.type() == QVariant::Invalid) ? v : v.toDouble()+1;
              }, "++"), 0);
    table.add(new UnaryOperation([](QVariant v) -> QVariant {
                  return (v.type() == QVariant::Invalid) ? v : v.toDouble()-1;
              }, "--"), 0);
    table.add(new BinaryOperation([](QVariant v1, QVariant v2) -> QVariant {
                  return (v1.type() == QVariant::Invalid || v2.type() == QVariant::Invalid) ?
                  QVariant{} : qPow(v1.toDouble(), v2.toDouble());
              }, "^"), 1);
    table.add(new BinaryOperation([](QVariant v1, QVariant v2) -> QVariant {
                  return (v1.type() == QVariant::Invalid || v2.type() == QVariant::Invalid) ?
                  QVariant{} : v1.toDouble() * v2.toDouble();
              }, "*"), 2);
    table.add(new BinaryOperation([](QVariant v1, QVariant v2) -> QVariant {
                  return (v1.type() == QVariant::Invalid || v2.type() == QVariant::Invalid) ?
                    QVariant{} : v1.toDouble() / v2.toDouble();
              }, "/"), 2);
    table.add(new BinaryOperation([](QVariant v1, QVariant v2) -> QVariant {
                  return (v1.type() == QVariant::Invalid || v2.type() == QVariant::Invalid) ?
                  QVariant{} : v1.toDouble() + v2.toDouble();
              }, "+"), 3);
    table.add(new BinaryOperation([](QVariant v1, QVariant v2) -> QVariant {
                  return (v1.type() == QVariant::Invalid || v2.type() == QVariant::Invalid) ?
                    QVariant{} : v1.toDouble() - v2.toDouble();
              }, "-"), 3);
    table.add(new BinaryOperation([](QVariant v1, QVariant v2) -> QVariant {
                  return (v1.type() == QVariant::Invalid || v2.type() == QVariant::Invalid) ?
                    QVariant{} : v1.toDouble() || v2.toDouble();
              }, "||"), 4);
    table.add(new BinaryOperation([](QVariant v1, QVariant v2) -> QVariant {
                  return (v1.type() == QVariant::Invalid || v2.type() == QVariant::Invalid) ?
                    QVariant{} : v1.toDouble() && v2.toDouble();
              }, "&&"), 4);

}

int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);

    QString str = "=5*++3";
    Parser parser(table, QSet<QString>{});
    QVariant value = parser.parse(str);
    qDebug() << "result is: " << ((value.type() == QVariant::Invalid) ? QString("####") : value.toString());
    return a.exec();


}




