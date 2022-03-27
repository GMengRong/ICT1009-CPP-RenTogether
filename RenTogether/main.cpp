#include "mainwindow.h"

#include <QApplication>
#include <iostream>

#include <QJsonDocument>
#include <QJsonParseError>
#include <QJsonObject>
#include <QJsonValue>
#include <QJsonArray>
#include <QObject>
#include <QFile>
#include <iostream>
#include <QDebug>
#include <string>
#include <QPoint>

//extern QList<QString> list1[3] = {};

int main(int argc, char *argv[])
{
    //int i =0;
    QApplication a(argc, argv);
    MainWindow w;
    w.show();

    QFile inFile("C:/Users/shahz/Desktop/RenTogether/electricBike.json");
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
//    qDebug() << "There are " << ptsArray.size() << "sets of points in the json file";
//    qDebug() << ptsArray[0];


    foreach(const QJsonValue & val, ptsArray){
        QString vehicleID =val.toObject().value("vehicleID").toString();
        QString brand =val.toObject().value("brand").toString();
        QString model =val.toObject().value("model").toString();
        QString basePrice =val.toObject().value("basePrice").toString();
        QString insuranceCoverage =val.toObject().value("insuranceCoverage").toString();
        QString pricePerCharge =val.toObject().value("pricePerCharge").toString();
        QString batteryLife =val.toObject().value("batteryLife").toString();
        qDebug() <<vehicleID;

    }

    QFile inFile2("C:/Users/shahz/Desktop/RenTogether/electricCar.json");
    inFile2.open(QIODevice::ReadOnly | QIODevice::Text);
    data = inFile2.readAll();
    inFile2.close();


    doc = QJsonDocument::fromJson(data, &errorPtr);
    if (doc.isNull()) {
       qDebug() << "Parse failed";
   }
    rootObj = doc.object();
    ptsArray = rootObj.value("electricCar").toArray();
//    qDebug() << "There are " << ptsArray.size() << "sets of points in the json file";
//    qDebug() << ptsArray[0];


    foreach(const QJsonValue & val, ptsArray){
        QString vehicleID =val.toObject().value("vehicleID").toString();
        QString brand =val.toObject().value("brand").toString();
        QString model =val.toObject().value("model").toString();
        QString basePrice =val.toObject().value("basePrice").toString();
        QString seaterNumber =val.toObject().value("seaterNumber").toString();
        QString insuranceCoverage =val.toObject().value("insuranceCoverage").toString();
        QString pricePerCharge =val.toObject().value("pricePerCharge").toString();
        QString batteryLife =val.toObject().value("batteryLife").toString();

        qDebug() << vehicleID;
    }

    QFile inFile3("C:/Users/shahz/Desktop/RenTogether/gasBike.json");
    inFile3.open(QIODevice::ReadOnly | QIODevice::Text);
    data = inFile3.readAll();
    inFile.close();


    doc = QJsonDocument::fromJson(data, &errorPtr);
    if (doc.isNull()) {
       qDebug() << "Parse failed";
   }
    rootObj = doc.object();
    ptsArray = rootObj.value("gasBike").toArray();
//    qDebug() << "There are " << ptsArray.size() << "sets of points in the json file";
//    qDebug() << ptsArray[0];


    foreach(const QJsonValue & val, ptsArray){
        QString vehicleID =val.toObject().value("vehicleID").toString();
        QString brand =val.toObject().value("brand").toString();
        QString model =val.toObject().value("model").toString();
        QString basePrice =val.toObject().value("basePrice").toString();
        QString insuranceCoverage =val.toObject().value("insuranceCoverage").toString();
        QString kmPerLitre =val.toObject().value("kmPerLitre").toString();

        qDebug() <<vehicleID;
    }

    QFile inFile4("C:/Users/shahz/Desktop/RenTogether/gasCar.json");
    inFile4.open(QIODevice::ReadOnly | QIODevice::Text);
    data = inFile4.readAll();
    inFile4.close();


    doc = QJsonDocument::fromJson(data, &errorPtr);
    if (doc.isNull()) {
       qDebug() << "Parse failed";
   }
    rootObj = doc.object();
    ptsArray = rootObj.value("gasCar").toArray();
//    qDebug() << "There are " << ptsArray.size() << "sets of points in the json file";
//    qDebug() << ptsArray[0];


    foreach(const QJsonValue & val, ptsArray){
        QString vehicleID =val.toObject().value("vehicleID").toString();
        QString brand =val.toObject().value("brand").toString();
        QString model =val.toObject().value("model").toString();
        QString basePrice =val.toObject().value("basePrice").toString();
        QString seaterNumber =val.toObject().value("seaterNumber").toString();
        QString insuranceCoverage =val.toObject().value("insuranceCoverage").toString();
        QString kmPerLitre =val.toObject().value("kmPerLitre").toString();

        qDebug() <<vehicleID;
    }

    QFile inFile5("C:/Users/shahz/Desktop/RenTogether/hybridBike.json");
    inFile5.open(QIODevice::ReadOnly | QIODevice::Text);
    data = inFile5.readAll();
    inFile5.close();


    doc = QJsonDocument::fromJson(data, &errorPtr);
    if (doc.isNull()) {
       qDebug() << "Parse failed";
   }
    rootObj = doc.object();
    ptsArray = rootObj.value("hybridBike").toArray();
//    qDebug() << "There are " << ptsArray.size() << "sets of points in the json file";
//    qDebug() << ptsArray[0];


    foreach(const QJsonValue & val, ptsArray){
        QString vehicleID =val.toObject().value("vehicleID").toString();
        QString brand =val.toObject().value("brand").toString();
        QString model =val.toObject().value("model").toString();
        QString basePrice =val.toObject().value("basePrice").toString();
        QString insuranceCoverage =val.toObject().value("insuranceCoverage").toString();
        QString pricePerCharge =val.toObject().value("pricePerCharge").toString();
        QString batteryLife =val.toObject().value("batteryLife").toString();
        QString kmPerLitre =val.toObject().value("kmPerLitre").toString();
        QString electricPriceModifier =val.toObject().value("electricPriceModifier").toString();
        QString gasPriceModifier =val.toObject().value("gasPriceModifier").toString();

        qDebug() <<vehicleID;
    }

    QFile inFile6("C:/Users/shahz/Desktop/RenTogether/hybridCar.json");
    inFile6.open(QIODevice::ReadOnly | QIODevice::Text);
    data = inFile6.readAll();
    inFile6.close();


    doc = QJsonDocument::fromJson(data, &errorPtr);
    if (doc.isNull()) {
       qDebug() << "Parse failed";
   }
    rootObj = doc.object();
    ptsArray = rootObj.value("hybridCar").toArray();
//    qDebug() << "There are " << ptsArray.size() << "sets of points in the json file";
//    qDebug() << ptsArray[0];


    foreach(const QJsonValue & val, ptsArray){
        QString vehicleID =val.toObject().value("vehicleID").toString();
        QString brand =val.toObject().value("brand").toString();
        QString model =val.toObject().value("model").toString();
        QString basePrice =val.toObject().value("basePrice").toString();
        QString seaterNumber =val.toObject().value("seaterNumber").toString();
        QString insuranceCoverage =val.toObject().value("insuranceCoverage").toString();
        QString pricePerCharge =val.toObject().value("pricePerCharge").toString();
        QString batteryLife =val.toObject().value("batteryLife").toString();
        QString kmPerLitre =val.toObject().value("kmPerLitre").toString();
        QString electricPriceModifier =val.toObject().value("electricPriceModifier").toString();
        QString gasPriceModifier =val.toObject().value("gasPriceModifier").toString();

        qDebug() <<vehicleID;

    }

    QFile inFile7("C:/Users/shahz/Desktop/RenTogether/user.json");
    inFile7.open(QIODevice::ReadOnly | QIODevice::Text);
    data = inFile7.readAll();
    inFile7.close();


    doc = QJsonDocument::fromJson(data, &errorPtr);
    if (doc.isNull()) {
       qDebug() << "Parse failed";
   }
    rootObj = doc.object();
    ptsArray = rootObj.value("user").toArray();
//    qDebug() << "There are " << ptsArray.size() << "sets of points in the json file";
//    qDebug() << ptsArray[0];


    foreach(const QJsonValue & val, ptsArray){
        QString userID =val.toObject().value("userID").toString();
        QString password =val.toObject().value("password").toString();
        qDebug() << userID;

    }
    return a.exec();
}
