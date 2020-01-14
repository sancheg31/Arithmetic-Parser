#include "TesterWindow.h"
#include "ui_TesterWindow.h"

TesterWindow::TesterWindow(IParserTemplateMethod* p, QWidget *parent) :
    QMainWindow(parent), ui(new Ui::TesterWindow), parser(p) {
    ui->setupUi(this);
    ui->result->setDigitCount(MAX_DIGIT_COUNT);
    ui->result->display(DEFAULT_VALUE);
    connect(ui->parseForm, SIGNAL(clicked()), SLOT(parseFormClicked()));
    connect(ui->clearForm, SIGNAL(clicked()), SLOT(clearClicked()));
}

TesterWindow::~TesterWindow() {
    delete ui;
}

void TesterWindow::parseFormClicked() {
    QString str = ui->form->toPlainText();
    QVariant result = parser->parse(str);
    displayResult(result);
}

void TesterWindow::clearClicked() {
    ui->result->display(DEFAULT_VALUE);
    ui->form->clear();
}
#include <QDebug>
void TesterWindow::displayResult(QVariant result) {
    if (result.isValid() && resultIsDouble(result))
        ui->result->display(result.toDouble());
    else
        ui->result->display(QString("FFFF"));
}
bool TesterWindow::resultIsDouble(QVariant result) const {
    bool ok;
    result.toDouble(&ok);
    return ok;
}
