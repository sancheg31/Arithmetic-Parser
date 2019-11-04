#include "TesterWindow.h"
#include "ui_TesterWindow.h"

TesterWindow::TesterWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::TesterWindow)
{
    ui->setupUi(this);
}

TesterWindow::~TesterWindow()
{
    delete ui;
}
