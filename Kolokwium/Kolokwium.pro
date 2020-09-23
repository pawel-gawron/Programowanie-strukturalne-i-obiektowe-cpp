TEMPLATE = app
CONFIG += console c++11
CONFIG -= app_bundle
CONFIG -= qt

INCLUDEPATH += "C:/SFML-2.5.1/include"

SOURCES += \
    duch.cpp \
    main.cpp \
    owoc.cpp \
    pacman.cpp \
    ruchomysprite.cpp


LIBS += -L"C:/SFML-2.5.1/lib"

CONFIG(debug, debug|release){
    LIBS += -lsfml-audio-d -lsfml-graphics-d -lsfml-network-d -lsfml-system-d -lsfml-window-d
} else {
    LIBS += -lsfml-audio -lsfml-graphics -lsfml-network -lsfml-system -lsfml-window
}

HEADERS += \
    duch.h \
    owoc.h \
    pacman.h \
    ruchomysprite.h
