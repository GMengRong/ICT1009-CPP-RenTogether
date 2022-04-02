QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

CONFIG += c++11


# You can make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

SOURCES += \
    RenTogether.cpp \
    jsonReader.cpp \
    main.cpp \
    mainwindow.cpp \
    rentalform.cpp \
    secdialog.cpp \
    objects/user.cpp 

HEADERS += \
    RenTogether.h \
    jsonReader.h \
    mainwindow.h \
    rentalform.h \
    secdialog.h \
    objects/user.h 

FORMS += \
    mainwindow.ui \
    rentalform.ui \
    secdialog.ui

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target

RESOURCES += \
    resources.qrc

DISTFILES += \
    hybridBike.json \
    hybridCar.json \
    gasCar.json \
    gasBike.json \
    electricBike.json \
    electricCar.json \
    user.json