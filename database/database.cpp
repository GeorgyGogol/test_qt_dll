#include "database.h"

#include <QtSql/QSqlError>
#include <QDebug>
#include <QtSql/QSqlQuery>
#include <QDir>

Database::Database()
{
    if (!QSqlDatabase::contains("MainCon")){
        db = QSqlDatabase::addDatabase("QSQLITE", "MainCon");
        QString path = QDir::currentPath() + "/TestDB";
        db.setDatabaseName(path);
    }
    else {
        db = QSqlDatabase::database("MainCon");
        qDebug() << db.databaseName();
    }

}

Database::~Database()
{
    Close();
}

bool Database::Open()
{
    bool res = db.open();

    if (!res) {
        qDebug() << "Connection is not opened!\n";
        qDebug() << db.lastError().text();
    }

    qDebug() << "Tables:\n";
    // Нормальные парни:
    // QStringList tables = db.tables();
    // for (int i = 0; i < tables.count(); ++i) {
    //     qDebug() << tables[i] << ";";
    // }
    // Я:
    for (auto table : db.tables()) {
        qDebug() << table << ";";
    }

    return res;
}

void Database::Close()
{
    db.close();
}

QSqlQueryModel* Database::recieveSomeData(QObject *parent)
{
    QSqlQuery query(db);
    QSqlQueryModel* out = nullptr;
    if (query.exec("SELECT TXT FROM SomeTable")) {
        out = new QSqlQueryModel(parent);
        out->setQuery(query);
    }
    else {
        qDebug() << "Error when recieving Data!\n";
        qDebug() << query.lastError().text();
    }
    return out;
}

