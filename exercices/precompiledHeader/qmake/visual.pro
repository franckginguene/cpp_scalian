TEMPLATE = app
DESTDIR 	= ./bin
QT -= gui

WINDOWS_TARGET_PLATFORM_VERSION=$$system(echo %WIN_SDK%)
CONFIG += console
QMAKE_CXXFLAGS += -O2

SOURCES += visual.cpp

PRECOMPILED_HEADER = headers.h