#-------------------------------------------------
#
# Project created by QtCreator 2017-12-27T09:55:39
#
#-------------------------------------------------

QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = Techies_Calculator
TEMPLATE = app

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
        main.cpp \
        Techies_Main.cpp \
    About.cpp \
    Magic_Res.cpp \
    Dmg_Red.cpp \
    Screen_Data.cpp

HEADERS += \
        Techies_Main.h \
    About.h \
    Magic_Res.h \
    Dmg_Red.h \
    Screen_Data.h

FORMS += \
        Techies_Main.ui \
    About.ui \
    Magic_Res.ui \
    Dmg_Red.ui

CONFIG += mobility
MOBILITY = 

RESOURCES += \
    resource.qrc

win32:RC_ICONS += techies.ico
