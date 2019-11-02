#pragma once

#include <QSet>
#include "OperationTable.h"
#include "IParserTemplateMethod.h"

class Parser: public IParserTemplateMethod {
public:
    Parser();
    Parser(const OperationTable&, const QSet<QString>&);

    void setCellNames(const QSet<QString> cells) { cellNames = cells; }
    void setTable(const OperationTable& t) { table = t; }
    virtual ~Parser() override;

protected:
    virtual QString setBrackets(const QString&) const override;
    virtual QString removeSpaces(const QString&) const override;
    virtual QVariant evalExpression(const QString &, int &) const override;
    virtual QVariant evalTerm(const QString &str, int &, int) const override;
    virtual QVariant evalFactor(const QString &str, int &) const override;

private:
    OperationTable table;
    QSet<QString> cellNames;
};

