TEMPLATE = app
CONFIG += console c++11
CONFIG -= app_bundle
CONFIG -= qt
LIBS += -lsfml-graphics -lsfml-window -lsfml-audio -lsfml-system -lsfml-network
SOURCES += \
        apple.cpp \
        game.cpp \
        main.cpp \
        snake.cpp \
        window.cpp

HEADERS += \
    apple.h \
    game.h \
    snake.h \
    window.h
