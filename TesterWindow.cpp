#include "TesterWindow.h"
#include "ui_TesterWindow.h"

TesterWindow::TesterWindow(IParserTemplateMethod* p, QWidget *parent) :
    QMainWindow(parent), ui(new Ui::TesterWindow), parser(p) {
    ui->setupUi(this);
    ui->result->setDigitCount(MAX_DIGIT_COUNT);
    connect(ui->parseForm, SIGNAL(clicked()), SLOT(parseFormClicked()));
}

TesterWindow::~TesterWindow() {
    delete ui;
}

void TesterWindow::parseFormClicked() {
    QString str = ui->form->toPlainText();
    QVariant result = parser->parse(str);
    displayResult(result);
}

void TesterWindow::displayResult(QVariant result) {
    if (result.isValid())
        ui->result->display(result.toString());
}
