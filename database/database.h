#ifndef DATABASE_H
#define DATABASE_H

#include <QtSql/QSqlDatabase>
#include <QtSql/QSqlQueryModel>

#include "database_global.h"
class DATABASESHARED_EXPORT Database
{

public:
    Database();
    ~Database();

private:
    QSqlDatabase db;

public:
    bool Open();
    void Close();

    QSqlQueryModel* recieveSomeData(QObject *parent);
};

#endif // DATABASE_H
