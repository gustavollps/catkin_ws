#-------------------------------------------------
#
# Project created by QtCreator 2016-05-10T00:45:54
#
#-------------------------------------------------

QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = serial_control
TEMPLATE = app


SOURCES += src/main_window.cpp \
    src/qnode.cpp \
    src/main.cpp

HEADERS  += include/serial_control/qnode.hpp \
    include/serial_control/main_window.hpp

FORMS    += ui/main_window.ui

RESOURCES += 

