QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

CONFIG += c++11

# You can make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

SOURCES += \
    baseObj/matrix.cpp \
    baseObj/transformmatrix.cpp \
    baseObj/vector3.cpp \
    camera.cpp \
    lightsourcepoint.cpp \
    drawer.cpp \
    main.cpp \
    mainwindow.cpp \
    scene.cpp \
    zbuffer.cpp \
    detail.cpp \
    light.cpp \
    figure.cpp

HEADERS += \
    baseObj/matrix.h \
    baseObj/transformmatrix.h \
    baseObj/vector3.h \
    baseObj/vector3.hpp \
    camera.h \
    lightsourcepoint.h \
    drawer.h \
    mainwindow.h \
    scene.h \
    zbuffer.h \
    light.h \
    baseObj/point.h \
    detail.h \
    figure.h

FORMS += mainwindow.ui

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target
