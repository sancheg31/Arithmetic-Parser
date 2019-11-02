#include "Parser.h"


Parser::Parser() { }

Parser::Parser(const OperationTable& t, const QSet<QString>& cell): table(t), cellNames(cell) { }

Parser::~Parser() { }

QString Parser::setBrackets(const QString& str) const {
    return str;
}

QString Parser::removeSpaces(const QString& str) const {
    return str;
}

QVariant Parser::evalExpression(const QString& str, int & pos) const {
    return str;
}

QVariant Parser::evalTerm(const QString &str, int & pos, int priority) const {
    return str;
}

QVariant Parser::evalFactor(const QString &str, int & pos) const {
    return str;
}
