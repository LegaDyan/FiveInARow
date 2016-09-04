#-------------------------------------------------
#
# Project created by QtCreator 2016-08-30T16:13:00
#
#-------------------------------------------------

QT       += core gui network

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = FiveInARowClient
TEMPLATE = app


SOURCES += main.cpp\
        mainwindow.cpp \
    chessboard.cpp \
    chess.cpp

HEADERS  += mainwindow.h \
    chessboard.h \
    chess.h

FORMS    += mainwindow.ui
