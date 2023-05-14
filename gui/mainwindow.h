#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private slots:
    void on_bFree_clicked();

    void on_bLoad_clicked();

    void on_bWork_clicked();

private:
    Ui::MainWindow *ui;
    HINSTANCE hDll = nullptr;

};

#endif // MAINWINDOW_H
