TEMPLATE = app

WINDOWS_TARGET_PLATFORM_VERSION=$$system(echo %WIN_SDK%)
SOURCES += *.cpp
DESTDIR 	= ./bin
CONFIG += console
QMAKE_CXXFLAGS += /w34061