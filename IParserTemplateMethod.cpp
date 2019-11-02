#include "IParserTemplateMethod.h"

IParserTemplateMethod::~IParserTemplateMethod() {}

QVariant IParserTemplateMethod::parse(const QString& str) const {
    QString temp = setBrackets(str);
    temp = removeSpaces(str);
    int pos = 0;
    temp.append(QChar::Null);
    QVariant result = evalExpression(temp, pos);
    return (str[pos] != QChar::Null) ? QVariant{} : result;
}

