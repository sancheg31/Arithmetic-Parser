#pragma once

#include <QSet>
#include "OperationTable.h"
#include "IParserTemplateMethod.h"

class Parser: public IParserTemplateMethod {
public:
    Parser();
    Parser(const OperationTable&, const QSet<QString>&);
    virtual ~Parser() override;

    virtual QVariant parse(const QString&) const override;
    void setCellNames(const QSet<QString> cells) { cellNames = cells; }
    void setTable(const OperationTable& t) { table = t; }


protected:
    Operation* currentOperation(const OperationContainer& cont, const QString&, int pos) const;
    QString setBracketsForUnaryOperations(const QString&) const;
    QString removeSpaces(const QString&) const;
    QVariant evalExpression(const QString &, int &) const;
    QVariant evalTerm(const QString &str, int &, int) const;
    QVariant evalFactor(const QString &str, int &) const;

private:
    OperationTable table;
    QSet<QString> cellNames;
};

