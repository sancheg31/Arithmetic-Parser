#include "ParserTester.h"


ParserTester::ParserTester(IParserTemplateMethod * p, QWidget * wgt): QTextEdit(wgt), parser(p) {

}

void ParserTester::slotCalculate() {
    QVariant result = parser->parse(toPlainText());
    emit resultCalculated(result.type() == QVariant::Invalid ? QString("####") : result.toString());
}
