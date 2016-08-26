QT += core
QT -= gui

CONFIG += c++11

TARGET = phonebook
CONFIG += console
CONFIG -= app_bundle

TEMPLATE = app

SOURCES += main.cpp \
    person.cpp \
    phonebook.cpp

HEADERS += \
    person.h \
    phonebook.h
