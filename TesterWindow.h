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

private:
    void displayResult(QVariant);

    const int MAX_DIGIT_COUNT = 16;
    Ui::TesterWindow *ui;
    IParserTemplateMethod* parser;

};
