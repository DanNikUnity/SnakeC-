QT       += widgets
TEMPLATE = app
TARGET   = Snake

DESTDIR  = ../build/bin
OBJECTS_DIR = ../build/obj
MOC_DIR     = ../build/moc

# Include biblioteca
INCLUDEPATH += ../SnakeCore
LIBS += -L../build/bin -lsnakecore

SOURCES += \
    main.cpp \
    mainwindow.cpp \
    gamefieldwidget.cpp \
    snaketimer.cpp

HEADERS += \
    mainwindow.hpp \
    gamefieldwidget.hpp \
    gameoverdialog.hpp \
    snaketimer.hpp
