TEMPLATE = app
CONFIG += console
CONFIG -= app_bundle


QT += core gui widgets opengl
SOURCES += main.cpp \
    creature.cpp \
    predator.cpp \
    prey.cpp \
    world.cpp \
    wall.cpp \
    coord.cpp \
    Utilities.cpp \
    hunter.cpp \
    infected.cpp \
    glwidget.cpp \
    ppsim.cpp \
    window.cpp

HEADERS += \
    creature.h \
    predator.h \
    prey.h \
    world.h \
    wall.h \
    utilities.h \
    coord.h \
    Constants.h \
    hunter.h \
    infected.h \
    glwidget.h \
    ppsim.h \
    window.h

