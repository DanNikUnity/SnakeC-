QT       -= gui

TEMPLATE = lib
CONFIG  += dll
TARGET   = snakecore

DESTDIR  = ../build/bin
OBJECTS_DIR = ../build/obj
MOC_DIR     = ../build/moc

INCLUDEPATH += $$PWD

HEADERS += \
    point.hpp \
    apple.hpp \
    board.hpp \
    snake.hpp \
    direction.hpp \
    painter_base.hpp \
    painter.hpp \
    game_engine.hpp

SOURCES += \
    point.cpp \
    apple.cpp \
    board.cpp \
    snake.cpp \
    direction.cpp \
    painter.cpp \
    game_engine.cpp
