Тестовый проект для изучения MVC
================================

Состав:
-------

N  |Модуль       |Зачем?
---|-------------|------
1  | database.dll| Модуль для взаимодействия с БД
2  | logic.dll   | Модуль-контроллер
3  | gui.exe     | Графическая оболочка с отображением

Теперь подробнее
================

Вообще нахуевертил, конечно. По-хорошему, модули должны быть
независимыми и заменяться в run-time, но в процессе изучения выяснил,
что фактически делаю статическую линковку. Суть в том, что проекты
связаны друг с другом (см. .pro файлы):

```
win32:CONFIG(release, debug|release): LIBS += -L$$PWD/../build/debug/database/release/ -ldatabase
else:win32:CONFIG(debug, debug|release): LIBS += -L$$PWD/../build/debug/database/debug/ -ldatabase

INCLUDEPATH += $$PWD/../database
DEPENDPATH += $$PWD/../database
```

И вот это вот равносильно статической настройке, что бы меню не говорило.
Для динамического использования модули вообще не должны ничего знать друг
о друге, а вызов и общение должно происходить по соглашению Си вот такими
штуками (примерно):

``` cpp
extern "C"
void __declspec(dllexport) viewSomeData(QTableView* pTable)
{
    Dll dll;
    dll.viewSomeData(pTable);
}
```

### Вывод

Проекты модулей не должны включаться друг в друга, но в то же время
очень удобно иметь класс модуля (в примере выше - класс Dll) и работать
с ним через адаптированные методы-обертки.

database.dll
------------

Модуль с "моделями" и всем необходимым для получения исходных выборок
из БД. Выполняет запрос и возвращает необработанные данные. Получилась
своего рода "обертка" для класса QSqlDatabase, только с определенными
запросами.

Есть идея именно его сделать своего рода синглтоном (по факту так оно
и есть).

logic.dll
---------

Модуль, который получает данные из базы и настраивает представление на
форме. В данном примере настройка происходит автоматически.

gui.exe
-------

Условный графический интерфейс. Вообще изначально тестировал
динамическое подключение, отключение, работу dll, так что какой
получился.

## Вывод

В процессе такого вот разделения интуиция подсказала, что хоть идея и
хороша, но все же не стоит дробить проект на подпроекты. Тем более, что
модель, контроллер и представление между собой очень тесно связано и
гораздо удобнее держать их вместе.

Могу допустить разделение на два проекта: в одном представление и контроллер, во втором - запросы. Оправдано, если в нескольких представлениях нужны примерно одни и те же выборки (такое вообще есть?). Тогда должно получится нечто подобное:

:::mermaid
flowchart TB
    gui1[gui1:\nview + controller] --> database.dll
    gui2[gui2:\nview + controller] --> database.dll
    gui3[gui3:\nview + controller] --> database.dll
:::

