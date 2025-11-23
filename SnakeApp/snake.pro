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
    mainwidget.cpp \
    timer.cpp

HEADERS += \
    mainwindow.hpp \
    mainwidget.hpp \
    gameoverdialog.hpp \
    timer.hpp
