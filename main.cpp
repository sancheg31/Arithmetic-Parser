#include <QCoreApplication>
#include <QDebug>

#include "Parser.h"
#include "Operation.h"
#include "UnaryOperation.h"
#include "OperationContainer.h"
#include "OperationTable.h"

int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);
    OperationTable table;
    table.add(new UnaryOperation([](QVariant v) -> QVariant { return v; }, "+"), 0);
    table.add(new UnaryOperation([](QVariant v) -> QVariant { return -v.toDouble(); }, "-"), 0);
    table.add(new UnaryOperation([](QVariant v) -> QVariant { return v.toDouble()+1; }, "++"), 0);
    table.add(new UnaryOperation([](QVariant v) -> QVariant { return v.toDouble()-1; }, "--"), 0);
    //table.add(new UnaryOperation([](QVariant v) -> QVariant { return v.toDouble()+2; }, "+++"), 0);
    //table.add(new UnaryOperation([](QVariant v) -> QVariant { return v.toDouble()-2; }, "---"), 0);
    table.add(new BinaryOperation([](QVariant v1, QVariant v2) -> QVariant { return v1.toDouble() * v2.toDouble(); }, "*"), 1);
    table.add(new BinaryOperation([](QVariant v1, QVariant v2) -> QVariant { return v1.toDouble() / v2.toDouble(); }, "/"), 1);
    table.add(new BinaryOperation([](QVariant v1, QVariant v2) -> QVariant { return v1.toDouble() + v2.toDouble(); }, "+"), 2);
    table.add(new BinaryOperation([](QVariant v1, QVariant v2) -> QVariant { return v1.toDouble() - v2.toDouble(); }, "-"), 2);
    //table.add(new BinaryOperation([](QVariant v1, QVariant v2) -> QVariant { return v1.toDouble() || v2.toDouble(); }, "||"), 3);
    //table.add(new BinaryOperation([](QVariant v1, QVariant v2) -> QVariant { return v1.toDouble() && v2.toDouble(); }, "&&"), 3);

    QString str = "= (3+2+4+8+(3*(8/--2)))";
    Parser parser(table, QSet<QString>{});
    qDebug() << "result is: " << parser.parse(str).toDouble();
    return a.exec();
}
