TEMPLATE = app
CONFIG += console c++11
CONFIG -= app_bundle
CONFIG -= qt

SOURCES += main.cpp \
    network_client.cpp \
    network_client_zeromq.cpp \
    network_client_raw.cpp \
    network_server.cpp

HEADERS += \
    network_client.h \
    network_client_zeromq.h \
    network_client_raw.h \
    network_server.h
