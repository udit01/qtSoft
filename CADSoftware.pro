#-------------------------------------------------
#
# Project created by QtCreator 2018-03-10T15:55:03
#
#-------------------------------------------------

QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = CADSoftware
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
    Graph.cpp \
    Line.cpp \
    Model3d.cpp \
    OrthographicViews.cpp \
    Plane.cpp \
    Point.cpp \
    Projection.cpp \
    DirectionCosines.cpp \
    main.cpp \
    mainwindow.cpp \
    generator3d.cpp \
    generator2d.cpp

HEADERS += \
    DirectionCosines.hpp \
    Graph.hpp \
    Line.hpp \
    Model3d.hpp \
    Point.hpp \
    OrthographicViews.hpp \
    Plane.hpp \
    Projection.hpp \
    mainwindow.h \
    generator3d.h \
    generator2d.h

FORMS += \
        mainwindow.ui \
    generator3d.ui \
    generator2d.ui
