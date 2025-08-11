QT       += core gui
QT += widgets quick quickwidgets



greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

CONFIG += c++17
CONFIG -= app_bundle
# You can make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0


# Protobuf paths for WSL
INCLUDEPATH += /usr/include
LIBS += -L/usr/lib/x86_64-linux-gnu -lprotobuf

INCLUDEPATH += /usr/include
LIBS += -L/usr/lib/x86_64-linux-gnu -lpaho-mqttpp3 -lpaho-mqtt3as

SOURCES += \
    Controller/cabintempcontrol.cpp \
    Controller/doorlockcontrol.cpp \
    Controller/fancontrol.cpp \
    Controller/gaugecontrol.cpp \
    Controller/lightcontrol.cpp \
    Controller/motortempcontrol.cpp \
    Controller/seatbeltcontrol.cpp \
    Controller/signallightcontrol.cpp \
    Controller/tripinfocontrol.cpp \
    Controller/warningcontrol.cpp \
    Model/model.cpp \
    main.cpp \
    mainwindow.cpp \
    protobuf/tempupdate.cpp \
    protobuf/weather.pb.cc

HEADERS += \
    Controller/cabintempcontrol.h \
    Controller/doorlockcontrol.h \
    Controller/fancontrol.h \
    Controller/gaugecontrol.h \
    Controller/lightcontrol.h \
    Controller/motortempcontrol.h \
    Controller/seatbeltcontrol.h \
    Controller/signallightcontrol.h \
    Controller/tripinfocontrol.h \
    Controller/warningcontrol.h \
    Model/model.h \
    includeFils.h \
    mainwindow.h \
    protobuf/tempupdate.h \
    protobuf/weather.pb.h


FORMS += \
    mainwindow.ui

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target



DISTFILES += \
    FuelGauge.qml \
    RpmGauge.qml \
    SpeedGauge.qml \
    protobuf/subscriber.py \
    protobuf/weather.proto \
    protobuf/weather_pb2.py

RESOURCES += \
    Image.qrc \
    resource.qrc
