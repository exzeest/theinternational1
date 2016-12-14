TEMPLATE = app

QT += widgets sql gui core

CONFIG += c++11

SOURCES += main.cpp \
    tree.cpp \
    interface.cpp

HEADERS += \
    tree.h \
    interface.h

FORMS += \
    interface.ui

RESOURCES += \
    res.qrc
