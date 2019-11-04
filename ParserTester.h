#pragma once

#include <QWidget>
#include <QTextEdit>

#include "IParserTemplateMethod.h"

class ParserTester: QTextEdit {
    Q_OBJECT
public:
    ParserTester(IParserTemplateMethod*, QWidget* = nullptr);

private:
    IParserTemplateMethod* parser;
private slots:
    void slotCalculate();

signals:
    void resultCalculated(const QString&);
};

