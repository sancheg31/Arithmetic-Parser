#include <QApplication>
#include <QDebug>
#include <QtMath>

#include "Parser.h"
#include "OperationFactory.h"
#include "OperationContainer.h"
#include "OperationPrecedenceTable.h"

#include "Validator.h"
#include "RegexValidator.h"

#include "TesterWindow.h"

OperationContainer createUnaryOperationsList(OperationFactory* factory) {
    OperationContainer result;
    result.insert(factory->createUnaryOperation([](QVariant v) -> QVariant { return (v.isValid()) ? v.toDouble() : v; }, "+"));
    result.insert(factory->createUnaryOperation([](QVariant v) -> QVariant { return (v.isValid()) ? -v.toDouble() : v; }, "-"));
    result.insert(factory->createUnaryOperation([](QVariant v) -> QVariant { return (v.isValid()) ? v.toDouble()+1 : v; }, "++"));
    result.insert(factory->createUnaryOperation([](QVariant v) -> QVariant { return (v.isValid()) ? v.toDouble()-1 : v; }, "--"));
    return result;
}

OperationContainer createBinaryOperationsList(OperationFactory* factory) {
    OperationContainer result;
    result.insert(factory->createBinaryOperation([](QVariant a, QVariant b) -> QVariant {
                      return (a.isValid() && b.isValid()) ? a.toDouble() + b.toDouble() : QVariant{};
                  }, "+"));
    result.insert(factory->createBinaryOperation([](QVariant a, QVariant b) -> QVariant {
                      return (a.isValid() && b.isValid()) ? a.toDouble() - b.toDouble() : QVariant{};
                  }, "-"));
    result.insert(factory->createBinaryOperation([](QVariant a, QVariant b) -> QVariant {
                      return (a.isValid() && b.isValid()) ? a.toDouble() * b.toDouble() : QVariant{};
                  }, "*"));
    result.insert(factory->createBinaryOperation([](QVariant a, QVariant b) -> QVariant {
                      return (a.isValid() && b.isValid()) ? a.toDouble() / b.toDouble() : QVariant{};
                  }, "/"));
    return result;
}

OperationPrecedenceTable createOperationTable() {
    OperationPrecedenceTable table;
    auto factory = OperationFactory::instance();
    auto unaryOperations = createUnaryOperationsList(factory);
    auto binaryOperations = createBinaryOperationsList(factory);
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

Validator* createValidator() {
    RegexValidator* regExpColumn = new RegexValidator(QRegExp(QString("[A-Za-z]{1,") + QString("1") + QString("}")));
    RegexValidator* regExpRow = new RegexValidator(QRegExp(QString("[1-9][0-9]{0,") + QString("}")));
    return new Validator({regExpRow, regExpColumn});
}

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    QString str = "=(++(++7)+(--6)*++12)";
    auto table = createOperationTable();
    auto validator = createValidator();
    Parser *parser = new Parser(table, QSet<QString>{}, validator);
    QVariant value = parser->parse(str);
    TesterWindow* window = new TesterWindow(parser);
    window->show();
    qDebug() << "result is: " << ((value.type() == QVariant::Invalid) ? QString("####") : value.toString());
    return a.exec();
}




