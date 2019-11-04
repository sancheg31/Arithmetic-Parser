#ifndef TESTERWINDOW_H
#define TESTERWINDOW_H

#include <QMainWindow>

namespace Ui {
class TesterWindow;
}

class TesterWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit TesterWindow(QWidget *parent = nullptr);
    ~TesterWindow();

private:
    Ui::TesterWindow *ui;
};

#endif // TESTERWINDOW_H
