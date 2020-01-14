#pragma once

#include <QSet>

#include "OperationPrecedenceTable.h"
#include "IParserTemplateMethod.h"

#include "Validator.h"
class Parser: public IParserTemplateMethod {
public:
    Parser(const OperationPrecedenceTable& table, const QSet<QString>& functions, Validator*);
    virtual ~Parser() override;

    virtual QVariant parse(const QString&) const override;
    void setCellNames(const QSet<QString> cells) { cellNames = cells; }
    void setTable(const OperationPrecedenceTable& t) { table = t; }

protected:
    virtual QString removeSpaces(const QString& str) const override;
    virtual QVariant evalExpression(const QString & str, int & pos) const override;
    virtual QVariant evalTerm(const QString &str, int & pos, int priority) const override;
    virtual QVariant evalFactor(const QString &str, int &pos) const override;

    QVariant getFactor(const QString& str, int& pos) const;
private:
    Validator* validator;
    OperationPrecedenceTable table;
    QSet<QString> cellNames;

};

