#-------------------------------------------------
#
# Project created by QtCreator 2012-09-19T09:36:07
#
#-------------------------------------------------

QT += network

CONFIG(debug, debug|release){
    TARGET = Fenetresd

    LIBS += -L../ctcpclient/debug -lctcpclientd \
              -L../configparser/debug -lconfigparserd \
              -L../GlobalesFonctions/debug -lGlobalesFonctionsd \
              -L../CSql/debug -lCSqld
}
CONFIG(release, debug|release){
    TARGET = Fenetres

    LIBS += -L../ctcpclient/release -lctcpclient \
                -L../configparser/release -lconfigparser \
                -L../GlobalesFonctions/release -lGlobalesFonctions \
                -L../CSql/release -lCSql
}
TEMPLATE = lib

DEFINES += FENETRES_LIBRARY

SOURCES += fenetres.cpp \
#    tcpfonctions.cpp \
            cmdpdlg.cpp

HEADERS += fenetres.h\
        Fenetres_global.h \
#    tcpfonctions.h \
        cmdpdlg.h


DEPENDPATH += ../ctcpclient \
            ../configparser \
            ../GlobalesFonctions \
            ../CSql

INCLUDEPATH += ../ctcpclient \
            ../configparser \
            ../GlobalesFonctions \
            ../CSql

#LIBS    += -lctcpclient \
#           -lconfigparser \
#           -lGlobalesFonctions

FORMS += \
    cmdpdlg.ui

RESOURCES += \
    icons.qrc

