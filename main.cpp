#include <QCoreApplication>
#include <QDebug>
#include <QtMath>

#include "Parser.h"
#include "IOperation.h"
#include "UnaryOperation.h"
#include "OperationContainer.h"
#include "OperationTable.h"

int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);
    OperationTable table;
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

    QString str = "=++(++7)+(--6)*++12)";
    Parser parser(table, QSet<QString>{});
    QVariant value = parser.parse(str);
    qDebug() << "result is: " << ((value.type() == QVariant::Invalid) ? QString("####") : value.toString());
    return a.exec();


}




