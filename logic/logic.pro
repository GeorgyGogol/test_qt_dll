#-------------------------------------------------
#
# Project created by QtCreator 2023-05-06T20:07:57
#
#-------------------------------------------------

QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = logic
TEMPLATE = lib

DEFINES += LOGIC_LIBRARY

# The following define makes your compiler emit warnings if you use
# any feature of Qt which has been marked as deprecated (the exact warnings
# depend on your compiler). Please consult the documentation of the
# deprecated API in order to know how to port your code away from it.
DEFINES += QT_DEPRECATED_WARNINGS

# You can also make your code fail to compile if you use deprecated APIs.
# In order to do so, uncomment the following line.
# You can also select to disable deprecated APIs only up to a certain version of Qt.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

SOURCES += \
        dll.cpp

HEADERS += \
        dll.h \
        logic_global.h

unix {
    target.path = /usr/lib
    INSTALLS += target
}

win32:CONFIG(release, debug|release): LIBS += -L$$PWD/../build/debug/database/release/ -ldatabase
else:win32:CONFIG(debug, debug|release): LIBS += -L$$PWD/../build/debug/database/debug/ -ldatabase

INCLUDEPATH += $$PWD/../database
DEPENDPATH += $$PWD/../database

