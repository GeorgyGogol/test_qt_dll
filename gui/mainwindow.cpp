#include "mainwindow.h"
#include "ui_mainwindow.h"

#include <windows.h>
#include "dll.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_bFree_clicked()
{
    FreeLibrary(hDll);
    hDll = nullptr;
    ui->bFree->setEnabled(false);
    ui->bWork->setEnabled(false);
    ui->bLoad->setDisabled(false);
}

void MainWindow::on_bLoad_clicked()
{
    [[maybe_unused]]
    bool isLoaded = false;
    //Q_UNUSED(isLoaded);


    hDll = LoadLibraryA("logic.dll");

    ui->bFree->setEnabled(hDll);
    ui->bWork->setEnabled(hDll);
    ui->bLoad->setDisabled(hDll);
}

void MainWindow::on_bWork_clicked()
{
    Dll lib;
    lib.viewSomeData(ui->tableView);

    /*
    if(!hDll) return;

    typedef void(*tf)(QTableView*);
    tf Func = tf(GetProcAddress(hDll, "viewSomeData"));

    if (Func) Func(ui->tableView);
    */

    /*
    if (Func)
        ui->listWidget->addItem(QString::number(Func()));
    */

    //ui->listWidget->addItem(QString::number(pLib->doSomeWork()));
}

