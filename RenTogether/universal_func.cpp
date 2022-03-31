#include <QDebug>
#include <QTextStream>
#include <QVector>
#include <QJsonDocument>
#include <QJsonParseError>
#include <QJsonObject>
#include <QJsonValue>
#include <QJsonArray>
#include <QObject>
#include <QFile>
#include <iostream>

#include "sessionVariables.h"
#include "objects/user.h"

void jsonReader()
{

    int i = 0;
    QFile inFile(":/data/data/electricBike.json");
    inFile.open(QIODevice::ReadOnly | QIODevice::Text);
    QByteArray data = inFile.readAll();
    inFile.close();

    QJsonParseError errorPtr;
    QJsonDocument doc = QJsonDocument::fromJson(data, &errorPtr);
    if (doc.isNull()) {
       qDebug() << "Parse failed";
    }
    QJsonObject rootObj = doc.object();
    QJsonArray ptsArray = rootObj.value("electricBike").toArray();

    foreach(const QJsonValue & val, ptsArray){
        electricBike[i].append(val.toObject().value("vehicleID").toString());
        electricBike[i].append(val.toObject().value("brand").toString());
        electricBike[i].append(val.toObject().value("model").toString());
        electricBike[i].append(val.toObject().value("basePrice").toString());
        electricBike[i].append(val.toObject().value("insuranceCoverage").toString());
        electricBike[i].append(val.toObject().value("pricePerCharge").toString());
        electricBike[i].append(val.toObject().value("batteryLife").toString());
        qDebug() << electricBike[i];
        i++;
    }

    // ----------------------------------------------------------------------------

    QFile inFile2(":/data/data/electricCar.json");
    inFile2.open(QIODevice::ReadOnly | QIODevice::Text);
    data = inFile2.readAll();
    inFile2.close();


    doc = QJsonDocument::fromJson(data, &errorPtr);
    if (doc.isNull()) {
       qDebug() << "Parse failed";
   }
    rootObj = doc.object();
    ptsArray = rootObj.value("electricCar").toArray();

    i = 0;
    foreach(const QJsonValue & val, ptsArray){
        electricCar[i].append(val.toObject().value("vehicleID").toString());
        electricCar[i].append(val.toObject().value("brand").toString());
        electricCar[i].append(val.toObject().value("model").toString());
        electricCar[i].append(val.toObject().value("basePrice").toString());
        electricCar[i].append(val.toObject().value("seaterNumber").toString());
        electricCar[i].append(val.toObject().value("insuranceCoverage").toString());
        electricCar[i].append(val.toObject().value("pricePerCharge").toString());
        electricCar[i].append(val.toObject().value("batteryLife").toString());
        qDebug() << electricCar[i];
        i++;
    }

    // ----------------------------------------------------------------------------

    QFile inFile3(":/data/data/gasBike.json");
    inFile3.open(QIODevice::ReadOnly | QIODevice::Text);
    data = inFile3.readAll();
    inFile.close();


    doc = QJsonDocument::fromJson(data, &errorPtr);
    if (doc.isNull()) {
       qDebug() << "Parse failed";
   }
    rootObj = doc.object();
    ptsArray = rootObj.value("gasBike").toArray();

    i = 0;
    foreach(const QJsonValue & val, ptsArray){
        gasBike[i].append(val.toObject().value("vehicleID").toString());
        gasBike[i].append(val.toObject().value("brand").toString());
        gasBike[i].append(val.toObject().value("model").toString());
        gasBike[i].append(val.toObject().value("basePrice").toString());
        gasBike[i].append(val.toObject().value("insuranceCoverage").toString());
        gasBike[i].append(val.toObject().value("kmPerLitre").toString());
        qDebug() << gasBike[i];
        i++;
    }

    // ----------------------------------------------------------------------------

    QFile inFile4(":/data/data/gasCar.json");
    inFile4.open(QIODevice::ReadOnly | QIODevice::Text);
    data = inFile4.readAll();
    inFile4.close();


    doc = QJsonDocument::fromJson(data, &errorPtr);
    if (doc.isNull()) {
       qDebug() << "Parse failed";
   }
    rootObj = doc.object();
    ptsArray = rootObj.value("gasCar").toArray();

    i = 0;
    foreach(const QJsonValue & val, ptsArray){
        gasCar[i].append(val.toObject().value("vehicleID").toString());
        gasCar[i].append(val.toObject().value("brand").toString());
        gasCar[i].append(val.toObject().value("model").toString());
        gasCar[i].append(val.toObject().value("basePrice").toString());
        gasCar[i].append(val.toObject().value("seaterNumber").toString());
        gasCar[i].append(val.toObject().value("insuranceCoverage").toString());
        gasCar[i].append(val.toObject().value("kmPerLitre").toString());
        qDebug() << gasCar[i];
        i++;
    }

    // ----------------------------------------------------------------------------

    QFile inFile5(":/data/data/hybridBike.json");
    inFile5.open(QIODevice::ReadOnly | QIODevice::Text);
    data = inFile5.readAll();
    inFile5.close();


    doc = QJsonDocument::fromJson(data, &errorPtr);
    if (doc.isNull()) {
       qDebug() << "Parse failed";
   }
    rootObj = doc.object();
    ptsArray = rootObj.value("hybridBike").toArray();

    i =0;
    foreach(const QJsonValue & val, ptsArray){
        hybridBike[i].append(val.toObject().value("vehicleID").toString());
        hybridBike[i].append(val.toObject().value("brand").toString());
        hybridBike[i].append(val.toObject().value("model").toString());
        hybridBike[i].append(val.toObject().value("basePrice").toString());
        hybridBike[i].append(val.toObject().value("insuranceCoverage").toString());
        hybridBike[i].append(val.toObject().value("pricePerCharge").toString());
        hybridBike[i].append(val.toObject().value("batteryLife").toString());
        hybridBike[i].append(val.toObject().value("kmPerLitre").toString());
        hybridBike[i].append(val.toObject().value("electricPriceModifier").toString());
        hybridBike[i].append(val.toObject().value("gasPriceModifier").toString());
        qDebug() << hybridBike[i];
        i++;
    }

    // ----------------------------------------------------------------------------

    QFile inFile6(":/data/data/hybridCar.json");
    inFile6.open(QIODevice::ReadOnly | QIODevice::Text);
    data = inFile6.readAll();
    inFile6.close();


    doc = QJsonDocument::fromJson(data, &errorPtr);
    if (doc.isNull()) {
       qDebug() << "Parse failed";
   }
    rootObj = doc.object();
    ptsArray = rootObj.value("hybridCar").toArray();

    i = 0;
    foreach(const QJsonValue & val, ptsArray){
        hybridCar[i].append(val.toObject().value("vehicleID").toString());
        hybridCar[i].append(val.toObject().value("brand").toString());
        hybridCar[i].append(val.toObject().value("model").toString());
        hybridCar[i].append(val.toObject().value("basePrice").toString());
        hybridCar[i].append(val.toObject().value("seaterNumber").toString());
        hybridCar[i].append(val.toObject().value("insuranceCoverage").toString());
        hybridCar[i].append(val.toObject().value("pricePerCharge").toString());
        hybridCar[i].append(val.toObject().value("batteryLife").toString());
        hybridCar[i].append(val.toObject().value("kmPerLitre").toString());
        hybridCar[i].append(val.toObject().value("electricPriceModifier").toString());
        hybridCar[i].append(val.toObject().value("gasPriceModifier").toString());
        qDebug() << hybridCar[i];
        i++;

    }

    // ----------------------------------------------------------------------------

    QFile inFile7(":/data/data/user.json");
    inFile7.open(QIODevice::ReadOnly | QIODevice::Text);
    data = inFile7.readAll();
    inFile7.close();

    doc = QJsonDocument::fromJson(data, &errorPtr);
    if (doc.isNull()) {
       qDebug() << "Parse failed";
    }
    rootObj = doc.object();
    ptsArray = rootObj.value("user").toArray();

//    i = 0;
    foreach(const QJsonValue & val, ptsArray) {
        const QString username = val.toObject().value("userID").toString();
        const QString password = val.toObject().value("password").toString();

        User user(username, password);
        userHashMap.insert(username, user);
//        user[i].append(val.toObject().value("userID").toString());
//        user[i].append(val.toObject().value("password").toString());
//        qDebug() << user[i];
//        i++;
        userHashMap[username].printUser();
    }

    // ----------------------------------------------------------------------------

}
