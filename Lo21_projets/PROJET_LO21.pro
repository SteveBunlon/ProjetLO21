#-------------------------------------------------
#
# Project created by QtCreator 2015-05-13T20:23:14
#
#-------------------------------------------------

QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = PROJET_LO21
TEMPLATE = app


SOURCES += main.cpp\
        mainwindow.cpp \
    timing.cpp \
    classes_cpp/Programmation.cpp \
    classes_cpp/Projet.cpp \
    classes_cpp/Tache.cpp \
    classes_cpp/Activite.cpp \
    edittache.cpp

HEADERS  += mainwindow.h \
    timing.h \
    classes/Programmation.h \
    classes/Projet.h \
    classes/Tache.h \
    classes/Activite.h \
    edittache.h

FORMS    += mainwindow.ui \
    edittache.ui
