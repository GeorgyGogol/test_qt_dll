#ifndef WINONE_H
#define WINONE_H

#include <QMainWindow>

namespace Ui {
class WinOne;
}

class WinOne : public QMainWindow
{
    Q_OBJECT

public:
    explicit WinOne(QWidget *parent = nullptr);
    ~WinOne();

public slots:
    void on_action_2_triggered();
    void on_action_3_triggered();

private:
    Ui::WinOne *ui;
};

#endif // WINONE_H
