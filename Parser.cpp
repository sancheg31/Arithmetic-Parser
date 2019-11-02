#include "Parser.h"


Parser::Parser() { }

Parser::Parser(const OperationTable& t, const QSet<QString>& cell): table(t), cellNames(cell) { }

Parser::~Parser() { }

QVariant Parser::parse(const QString & str) const {
    QString temp = str;
    temp = temp.mid(1);
    temp.push_front('(');
    temp.push_back(')');
    temp.append(QChar::Null);
    temp = setBracketsForUnaryOperations(str);
    temp = removeSpaces(temp);
    int pos = 0;
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

QPair<Operation*, int> Parser::nearestOperation(const OperationContainer &cont, const QString & str, int pos) const {
    int minIndex = str.size();
    Operation* result = nullptr;
    for (auto & op: cont) {
        int curIndex = str.indexOf(op->notation(), pos);
        if (curIndex < minIndex) {
            minIndex = curIndex;
            result = op;
        }
    }
    return QPair{result, minIndex};
}

QVector<QPair<Operation*, int>> Parser::operationList(const OperationContainer& cont, const QString& str, int pos) const {
    QVector<QPair<Operation*, int>> result;
    for( ; pos < str.size(); ) {
        auto pair = nearestOperation(cont, str, pos);
        if (pair.first == nullptr)
            return result;
        pos = pair.second + 1;
        result.push_back(pair);
    }
    return result;
}

QVariant Parser::getFactor(const QString &str, int &pos) const {
    QVariant result;
    QRegExp regExpColumn(QString("[A-Za-z]{0,") + QString("1") + QString("}"));
    QRegExp regExpRow(QString("[1-9][0-9]{0,") + QString("1") + QString("}"));
    QString column;
    while (str[pos].isLetter()) {
        column += str[pos];
        ++pos;
    }
    QString row;
    while (str[pos].isNumber() || str[pos] == '.') {
        row += str[pos];
        ++pos;
    }
    if (regExpColumn.exactMatch(column) && regExpRow.exactMatch(row)) {
        //Get Cell Value From TableWidget!!!!!!!!!!!!!!!!!!
    } else {
        bool ok;
        result = (column+row).toDouble(&ok);
        if (!ok)
            result = QVariant{};
    }
    return result;
}

QString Parser::setBracketsForUnaryOperations(const QString& str) const {
    QString temp = str;
    auto opList = operationList(table[0], str, 0);
    for(auto & pair: opList) {
        int pos = pair.second + pair.first->notation().size();
        int start = pos;
        QVariant result = getFactor(temp, pos);
        int end = pos;
        temp.insert(start, QString("(") + QString(temp[start]));
        temp.insert(end, QString(")") + QString(temp[end]));
    }
    return temp;
}

QString Parser::removeSpaces(const QString& str) const {
    QString temp = str;
    temp.replace(" ", "");
    return temp;
}

QVariant Parser::evalExpression(const QString& str, int & pos) const {
    QVariant result = evalTerm(str, pos, table.columnCount()-2);
    while (str[pos] != QChar::Null) {
        BinaryOperation* curOperation = dynamic_cast<BinaryOperation*>(currentOperation(table[table.columnCount()-1], str, pos));
        if (curOperation == nullptr)
            return result;
        ++pos;
        QVariant term = evalTerm(str, pos, table.columnCount()-2);
        if (result.type() != QVariant::Double || term.type() != QVariant::Double)
            return QVariant{};
        result = curOperation->operator()(result, term);
    }
    return result;
}

QVariant Parser::evalTerm(const QString& str, int & pos, int priority) const {
    QVariant result = (priority) ? evalTerm(str, pos, priority-1) : evalFactor(str, pos);
    while (str[pos] != QChar::Null) {
        BinaryOperation* curOperation = dynamic_cast<BinaryOperation*>(currentOperation(table[priority], str, pos));
        if (curOperation == nullptr)
            return result;
        ++pos;
        QVariant term = (priority) ? evalTerm(str, pos, priority-1) : evalFactor(str, pos);
        if (result.type() != QVariant::Double || term.type() != QVariant::Double)
            return QVariant{};
        result = curOperation->operator()(result, term);
    }
    return result;
}

QVariant Parser::evalFactor(const QString& str, int& pos) const {
    QVariant result;
    UnaryOperation* curOperation = nullptr;
    if (str[pos] == '(') {
        ++pos;
        result = evalExpression(str, pos);
        if (str[pos] != ')')
            result = QVariant{};
        ++pos;
    } else {
        curOperation = dynamic_cast<UnaryOperation*>(currentOperation(table[0], str, pos));
        if (curOperation != nullptr)
            pos += curOperation->notation().size();
        result = getFactor(str, pos);
    }
    if (curOperation) {
        result = curOperation->operator()(result);
    }
    return result;
}
/*
QVariant evalExpression(const QString &str, int &pos) {

    QVariant result = evalTerm(str, pos);
    while (str[pos] != QChar::Null) {
        QChar op = str[pos];
        if (op != '+' && op != '-')
            return result;
        ++pos;

        QVariant term = evalTerm(str, pos);
        if (result.type() == QVariant::Double
                && term.type() == QVariant::Double) {
            if (op == '+') {
                result = result.toDouble() + term.toDouble();
            } else {
                result = result.toDouble() - term.toDouble();
            }
        } else {
            result = QVariant{};
        }
    }
    return result;
}

QVariant evalTerm(const QString &str, int & pos, int priority) {
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

QVariant evalFactor(const QString &str, int & pos) {
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
            if (c) {
                result = c->value();
            } else {
                result = 0.0;
            }
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
*/
