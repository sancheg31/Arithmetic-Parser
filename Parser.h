#pragma once

#include <QSet>

#include "OperationTable.h"
#include "IParserTemplateMethod.h"

class Parser: public IParserTemplateMethod {
public:
    Parser(const OperationTable& table, const QSet<QString>& functions);
    virtual ~Parser() override;

    virtual QVariant parse(const QString&) const override;
    void setCellNames(const QSet<QString> cells) { cellNames = cells; }
    void setTable(const OperationTable& t) { table = t; }

protected:
    virtual QString removeSpaces(const QString& str) const override;
    virtual QVariant evalExpression(const QString & str, int & pos) const override;
    virtual QVariant evalTerm(const QString &str, int & pos, int priority) const override;
    virtual QVariant evalFactor(const QString &str, int &pos) const override;

    QVariant getFactor(const QString& str, int& pos) const;
private:
    OperationTable table;
    QSet<QString> cellNames;

};

