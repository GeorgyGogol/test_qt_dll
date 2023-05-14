#include "dll.h"

//#include "winone.h"

#include "database.h"
#include <QtSql/QSqlQueryModel>
#include <QMessageBox>

#include<QThread>

Dll::Dll()
{
}

int Dll::doSomeWork()
{
    //WinOne* window = new WinOne;
    //window->show();

    QThread::msleep(5000);

    return 5;
}

void Dll::viewSomeData(QTableView* pTable)
{
    Database db;
    db.Open();
    QSqlQueryModel* model = db.recieveSomeData(pTable);
    if (model) {
        model->sort(0, Qt::DescendingOrder);
        pTable->setModel(model);
    }
    QMessageBox::information(nullptr, "Dll", "Okay");
}

extern "C"
void __declspec(dllexport) viewSomeData(QTableView* pTable)
{
    Dll dll;
    dll.viewSomeData(pTable);
}

/*
extern "C"
int __declspec(dllexport) doSomeWork2()
{
    Dll dll;
    return dll.doSomeWork();
}
*/
