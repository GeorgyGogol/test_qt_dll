#ifndef DLL_H
#define DLL_H

#include <QTableView>

#include "logic_global.h"
class LOGICSHARED_EXPORT Dll
{

public:
    Dll();

public:
    int doSomeWork();

    void viewSomeData(QTableView* pTable);

};

//extern "C"
//int __declspec(dllexport) doSomeWork2();

extern "C"
void __declspec(dllexport) viewSomeData(QTableView* pTable);

#endif // DLL_H
