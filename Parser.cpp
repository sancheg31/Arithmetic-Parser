#include "Parser.h"


Parser::Parser() { }

Parser::Parser(const OperationTable& t, const QSet<QString>& cell): table(t), cellNames(cell) { }

Parser::~Parser() { }

QVariant Parser::parse(const QString & str) const {
    QString temp = setBracketsForUnaryOperations(str);
    temp = removeSpaces(temp);
    int pos = 0;
    temp.append(QChar::Null);
    QVariant result = evalExpression(temp, pos);
    return (str[pos] != QChar::Null) ? QVariant{} : result;
}

Operation* Parser::currentOperation(const OperationContainer &cont, const QString & str, int pos) const {
    for (auto & op : cont) {
        int curIndex = str.indexOf(op->notation(), pos);
        if (curIndex == pos)
            return op;
    }
    return nullptr;
}

QString Parser::setBracketsForUnaryOperations(const QString& str) const {
    return str;
}

QString Parser::removeSpaces(const QString& str) const {
    return str;
}

QVariant Parser::evalExpression(const QString& str, int & pos) const {
    QVariant result = evalTerm(str, pos, table.columnCount()-2);
    BinaryOperation* curOperation = dynamic_cast<BinaryOperation*>(currentOperation(table[table.columnCount()-1], str, pos));

}

QVariant Parser::evalTerm(const QString &str, int & pos, int priority) const {
    QVariant result = (priority) ? evalTerm(str, pos, priority-1) : evalFactor(str, pos);
    while (str[pos] != QChar::Null) {
        QChar op = str[pos];
        if (op != '*' && op != '/')
            return result;
        ++pos;

        QVariant factor = (priority) ? evalTerm(str, pos, priority-1) : evalFactor(str, pos);
        if (result.type() == QVariant::Double
                && factor.type() == QVariant::Double) {
            if (op == '*') {
                result = result.toDouble() * factor.toDouble();
            } else {
                if (factor.toDouble() == 0.0) {
                    result = QVariant{};
                } else {
                    result = result.toDouble() / factor.toDouble();
                }
            }
        } else {
            result = QVariant{};
        }
    }
    return result;
}

QVariant Parser::evalFactor(const QString &str, int & pos) const {
    QVariant result;
    bool negative = false;

    if (str[pos] == '-') {
        negative = true;
        ++pos;
    }

    if (str[pos] == '(') {
        ++pos;
        result = evalExpression(str, pos);
        if (str[pos] != ')')
            result = QVariant{};
        ++pos;
    } else {
        QRegExp regExp("[A-Za-z][1-9][0-9]{0,2}");
        QString token;

        while (str[pos].isLetterOrNumber() || str[pos] == '.') {
            token += str[pos];
            ++pos;
        }

        if (regExp.exactMatch(token)) {
            int column = token[0].toUpper().unicode() - 'A';
            int row = token.mid(1).toInt() - 1;

            //Cell *c = static_cast<Cell *>(tableWidget()->item(row, column));
            /*if (c) {
                result = c->value();
            } else {
                result = 0.0;
            }*/
        } else {
            bool ok;
            result = token.toDouble(&ok);
            if (!ok)
                result = QVariant{};
        }
    }

    if (negative) {
        if (result.type() == QVariant::Double) {
            result = -result.toDouble();
        } else {
            result = QVariant::Invalid;
        }
    }
    return result;
}
