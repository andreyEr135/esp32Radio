QT       += core gui network

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

CONFIG += c++11

# You can make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

TARGET = WiFiRadioConfig
TEMPLATE = app

SOURCES += \
    dynamicImageButton.cpp \
    dynamicbutton.cpp \
    main.cpp \
    mapform.cpp \
    radioinfo.cpp \
    wifiradioconfig.cpp \
    wifisearch.cpp

HEADERS += \
    dynamicImageButton.h \
    dynamicbutton.h \
    mapform.h \
    radioinfo.h \
    wifiradioconfig.h \
    wifisearch.h

FORMS += \
    form.ui \
    mapform.ui \
    wifiradioconfig.ui \
    wifisearch.ui

TRANSLATIONS += \
    WiFiRadioConfig_ru_RU.ts
CONFIG += lrelease
CONFIG += embed_translations

#Linkage for MapGraphics shared library
win32:CONFIG(release, debug|release): LIBS += -L$$OUT_PWD/../MapGraphics/release/ -lMapGraphics
else:win32:CONFIG(debug, debug|release): LIBS += -L$$OUT_PWD/../MapGraphics/debug/ -lMapGraphics
else:unix:!symbian: LIBS += -L$$OUT_PWD/../MapGraphics/ -lMapGraphics

INCLUDEPATH += $$PWD/../MapGraphics
DEPENDPATH += $$PWD/../MapGraphics


# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
#!isEmpty(target.path): INSTALLS += target

RESOURCES += \
    images.qrc

RC_ICONS = /images/icon.ico
