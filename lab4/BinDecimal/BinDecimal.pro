QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

CONFIG += c++11

# You can make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

SOURCES += \
    main.cpp \
    mainwindow.cpp

HEADERS += \
    mainwindow.h

FORMS += \
    mainwindow.ui

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target

win32: LIBS += -L$$PWD/staticLib/debuge/ -lstaticLib

INCLUDEPATH += $$PWD/staticLib/include
DEPENDPATH += $$PWD/staticLib/include

win32:!win32-g++: PRE_TARGETDEPS += $$PWD/staticLib/debuge/staticLib.lib
else:win32-g++: PRE_TARGETDEPS += $$PWD/staticLib/debuge/libstaticLib.a
