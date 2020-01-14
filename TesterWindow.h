#pragma once

#include <QMainWindow>

#include "Parser.h"
#include "IParserTemplateMethod.h"

namespace Ui {
class TesterWindow;
}

class TesterWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit TesterWindow(IParserTemplateMethod*, QWidget *parent = nullptr);
    ~TesterWindow();

private slots:
    void parseFormClicked();
    void clearClicked();

private:
    void displayResult(QVariant);

    bool resultIsDouble(QVariant result) const;

    const int MAX_DIGIT_COUNT = 16;
    const QString DEFAULT_VALUE = QString::number(0);
    Ui::TesterWindow *ui;
    IParserTemplateMethod* parser;

};
