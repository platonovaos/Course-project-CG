QT       += core gui opengl

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = QT_OpenGL
TEMPLATE = app

DEFINES += QT_DEPRECATED_WARNINGS

SOURCES += \
    main.cpp \
    mainwindow.cpp \
    viewportwidget.cpp \
    point.cpp \
    datail.cpp

HEADERS += \
    mainwindow.h \
    viewportwidget.h \
    point.h \
    detail.h

FORMS += \
    mainwindow.ui

#LINUX
LIBS += -lglut -lGLU
