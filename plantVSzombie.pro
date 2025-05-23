#-------------------------------------------------
#
# Project created by QtCreator 2020-12-03T10:40:51
#
#-------------------------------------------------

QT       += core gui multimedia


greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = plantVSzombie
TEMPLATE = app
QMAKE_CXXFLAGS +=  -Wno-unused-parameter
RC_ICONS = logo.ico

# The following define makes your compiler emit warnings if you use
# any feature of Qt which as been marked as deprecated (the exact warnings
# depend on your compiler). Please consult the documentation of the
# deprecated API in order to know how to port your code away from it.
DEFINES += QT_DEPRECATED_WARNINGS

# You can also make your code fail to compile if you use deprecated APIs.
# In order to do so, uncomment the following line.
# You can also select to disable deprecated APIs only up to a certain version of Qt.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0


SOURCES += \
    main.cpp \
    mainwindow.cpp \
    basiczombie.cpp \
    bucketzombie.cpp \
    button.cpp \
    card.cpp \
    cherrybomb.cpp \
    conezombie.cpp \
    footballzombie.cpp \
    map.cpp \
    mower.cpp \
    pea.cpp \
    plant.cpp \
    potatomine.cpp \
    repeater.cpp \
    screenzombie.cpp \
    shop.cpp \
    shovel.cpp \
    snowpea.cpp \
    startwindow.cpp \
    sun.cpp \
    sunflower.cpp \
    wallnut.cpp \
    zombie.cpp \
    newspaperzombie.cpp \
    pumpkin.cpp \
    file.cpp \
    scorecard.cpp \
    interface.cpp

HEADERS += \
    mainwindow.h \
    basiczombie.h \
    bucketzombie.h \
    button.h \
    card.h \
    cherrybomb.h \
    conezombie.h \
    footballzombie.h \
    map.h \
    mower.h \
    pea.h \
    plant.h \
    repeater.h \
    screenzombie.h \
    potatomine.h \
    shop.h \
    shovel.h \
    snowpea.h \
    startwindow.h \
    sunflower.h \
    sun.h \
    wallnut.h \
    zombie.h \
    basic.h \
    newspaperzombie.h \
    pumpkin.h \
    file.h \
    scorecard.h \
    interface.h

FORMS += \
        mainwindow.ui

RESOURCES += \
    qrc.qrc

DISTFILES +=


