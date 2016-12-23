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

DISTFILES += \
    Icons/-.png \
    Icons/Bar selected.png \
    Icons/barSearch.png \
    Icons/Buttons.png \
    Icons/divisor.png \
    Icons/Frame.png \
    Icons/FullScr.png \
    Icons/gear.png \
    Icons/Header.png \
    Icons/icon desktop.png \
    Icons/icon document.png \
    Icons/Icon gear.png \
    Icons/icon grid.png \
    Icons/icon list.png \
    Icons/icon options.png \
    Icons/icon Pictures.png \
    Icons/icon recent.png \
    Icons/icon Search.png \
    Icons/icon trash.png \
    Icons/iconSearch.png \
    Icons/Left.png \
    Icons/LEFTARROW.png \
    Icons/RIGHTARROW.png \
    Icons/SaveCom.png \
    Icons/Search.png \
    Icons/selected.png
