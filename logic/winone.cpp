#include "winone.h"
#include "ui_winone.h"

#include "database.h"

WinOne::WinOne(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::WinOne)
{
    ui->setupUi(this);
}

WinOne::~WinOne()
{
    delete ui;
}

void WinOne::on_action_2_triggered()
{
    Database db;
    if (!db.Open()) return;
}

void WinOne::on_action_3_triggered()
{
    //ui->
}

