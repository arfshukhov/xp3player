QT       += core gui
QT += multimedia
QT += core5compat
greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

CONFIG += c++17

# You can make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

VERSION = 1.0.1
QMAKE_TARGET_COMPANY = Larionov Software
QMAKE_TARGET_PRODUCT = XP3Player
QMAKE_TARGET_DESCRIPTION = Lightweight music player
QMAKE_TARGET_COPYRIGHT = Larionov Vladimir Vladimirovich

SOURCES += \
    logic.cpp \
    main.cpp \
    mainwindow.cpp

HEADERS += \
    logic.h \
    mainwindow.h

FORMS += \
    mainwindow.ui

TRANSLATIONS += \
    player_ru_RU.ts
CONFIG += release
CONFIG += embed_translations

QMAKE_LFLAGS = -static -static-libgcc

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target

DISTFILES += \
    mainwindow.qml

RC_ICON =  icon.png
