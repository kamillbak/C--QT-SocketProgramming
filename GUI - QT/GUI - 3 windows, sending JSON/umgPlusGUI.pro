QT       += core gui network charts

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

CONFIG += c++11

# You can make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

SOURCES += \
    chartswindow.cpp \
    data.cpp \
    fdwindow.cpp \
    main.cpp \
    mainwindow.cpp \
    pathwindow.cpp

HEADERS += \
    chartswindow.h \
    data.h \
    fdwindow.h \
    mainwindow.h \
    pathwindow.h

FORMS += \
    chartswindow.ui \
    fdwindow.ui \
    mainwindow.ui \
    pathwindow.ui

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target

DISTFILES += \
    Desription
