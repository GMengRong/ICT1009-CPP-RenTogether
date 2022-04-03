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

#include "jsonreader.h"

QHash<QString, User> &jsonReader::getUserHashMap()
{
    return userHashMap;
}

QHash<int, ElectricMotorbike> &jsonReader::getElectricBike()
{
    return electricBike;
}

QHash<int, ElectricCar> &jsonReader::getElectricCar()
{
    return electricCar;
}

QHash<int, GasMotorbike> &jsonReader::getGasBike()
{
    return gasBike;
}

QHash<int, GasCar> &jsonReader::getGasCar()
{
    return gasCar;
}

QHash<int, HybridMotorbike> &jsonReader::getHybridBike()
{
    return hybridBike;
}

QHash<int, HybridCar> &jsonReader::getHybridCar()
{
    return hybridCar;
}

QList<Vehicle> jsonReader::getAllHashmap()
{
//    int i=0;
//    int totalSize = electricBike.size() + electricCar.size() + gasBike.size() + gasCar.size() + hybridBike.size() + hybridCar.size();
//    Vehicle allVehicles[totalSize];
    QList<Vehicle> allVehicles;

    for (Vehicle i : electricBike.values()) {
        allVehicles.append(i);
    }

    for (Vehicle i : electricCar.values()) {
        allVehicles.append(i);
    }
    for (Vehicle i : gasBike.values()) {
        allVehicles.append(i);
    }
    for (Vehicle i : gasCar.values()) {
        allVehicles.append(i);
    }
    for (Vehicle i : hybridBike.values()) {
        allVehicles.append(i);
    }
    for (Vehicle i : hybridCar.values()) {
        allVehicles.append(i);
    }

    return allVehicles;
}

jsonReader::jsonReader()
{

//    int i = 0;
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

    foreach(const QJsonValue & val, ptsArray) {
        int vehicleID = val.toObject().value("vehicleID").toString().toInt();
        qDebug() << vehicleID;

        QString brand = val.toObject().value("brand").toString();
        QString model = val.toObject().value("model").toString();
        double mileage = val.toObject().value("mileage").toString().toDouble();
        double basePrice = val.toObject().value("basePrice").toString().toDouble();
        int insuranceCoverage = val.toObject().value("insuranceCoverage").toString().toInt();

        double pricePerCharge = val.toObject().value("pricePerCharge").toString().toDouble();
        int batteryLife = val.toObject().value("batteryLife").toString().toInt();

        ElectricMotorbike eb(vehicleID, brand, model, mileage, basePrice, insuranceCoverage, pricePerCharge, batteryLife);
        electricBike.insert(vehicleID, eb);
    }

//    foreach(const QJsonValue & val, ptsArray){
//        electricBike[i].append(val.toObject().value("vehicleID").toString());
//        electricBike[i].append(val.toObject().value("brand").toString());
//        electricBike[i].append(val.toObject().value("model").toString());
//        electricBike[i].append(val.toObject().value("basePrice").toString());
//        electricBike[i].append(val.toObject().value("insuranceCoverage").toString());
//        electricBike[i].append(val.toObject().value("pricePerCharge").toString());
//        electricBike[i].append(val.toObject().value("batteryLife").toString());
//        qDebug() << electricBike[i];
//        i++;
//    }


//    ElectricMotorbike EBike1(1, "TOKYODRIFT", "SWIFT", 102.5, 250.9, 20000, 75, 120);
//    ElectricMotorbike EBike2(2, "TOKYODRIFT2", "SWIdsaFT", 152.5, 30.9, 10000, 85, 90);
//    ElectricMotorbike EBike3(3, "TOKYODRIFT3", "EMBVS", 22.5, 70.9, 25000, 95, 110);

//    electricBike.insert("1", EBike1);
//    electricBike.insert("2", EBike2);
//    electricBike.insert("3", EBike3);


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

    foreach(const QJsonValue & val, ptsArray) {
        int vehicleID = val.toObject().value("vehicleID").toString().toInt();
        qDebug() << vehicleID;

        QString brand = val.toObject().value("brand").toString();
        QString model = val.toObject().value("model").toString();
        double mileage = val.toObject().value("mileage").toString().toDouble();

        double basePrice = val.toObject().value("basePrice").toString().toDouble();
        int seaterNumber = val.toObject().value("seaterNumber").toString().toInt();

        int insuranceCoverage = val.toObject().value("insuranceCoverage").toString().toInt();
        double pricePerCharge = val.toObject().value("pricePerCharge").toString().toDouble();
        int batteryLife = val.toObject().value("batteryLife").toString().toInt();

        ElectricCar ec(vehicleID, brand, model, mileage, basePrice, seaterNumber, insuranceCoverage, pricePerCharge, batteryLife);
        electricCar.insert(vehicleID, ec);
    }


//    foreach(const QJsonValue & val, ptsArray){
//        electricCar[i].append(val.toObject().value("vehicleID").toString());
//        electricCar[i].append(val.toObject().value("brand").toString());
//        electricCar[i].append(val.toObject().value("model").toString());
//        electricCar[i].append(val.toObject().value("basePrice").toString());
//        electricCar[i].append(val.toObject().value("seaterNumber").toString());
//        electricCar[i].append(val.toObject().value("insuranceCoverage").toString());
//        electricCar[i].append(val.toObject().value("pricePerCharge").toString());
//        electricCar[i].append(val.toObject().value("batteryLife").toString());
//        qDebug() << electricCar[i];
//        i++;
//    }

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

    foreach(const QJsonValue & val, ptsArray) {
        int vehicleID = val.toObject().value("vehicleID").toString().toInt();
        qDebug() << vehicleID;

        QString brand = val.toObject().value("brand").toString();
        QString model = val.toObject().value("model").toString();
        double mileage = val.toObject().value("mileage").toString().toDouble();

        double basePrice = val.toObject().value("basePrice").toString().toDouble();
        int insuranceCoverage = val.toObject().value("insuranceCoverage").toString().toInt();

        double kmPerLitre = val.toObject().value("kmPerLitre").toString().toDouble();

        GasMotorbike gb(vehicleID, brand, model, mileage, basePrice, insuranceCoverage, kmPerLitre);
        gasBike.insert(vehicleID, gb);
    }

//    foreach(const QJsonValue & val, ptsArray){
//        gasBike[i].append(val.toObject().value("vehicleID").toString());
//        gasBike[i].append(val.toObject().value("brand").toString());
//        gasBike[i].append(val.toObject().value("model").toString());
//        gasBike[i].append(val.toObject().value("basePrice").toString());
//        gasBike[i].append(val.toObject().value("insuranceCoverage").toString());
//        gasBike[i].append(val.toObject().value("kmPerLitre").toString());
//        qDebug() << gasBike[i];
//        i++;
//    }

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

    foreach(const QJsonValue & val, ptsArray) {
        int vehicleID = val.toObject().value("vehicleID").toString().toInt();
        qDebug() << vehicleID;

        QString brand = val.toObject().value("brand").toString();
        QString model = val.toObject().value("model").toString();
        double mileage = val.toObject().value("mileage").toString().toDouble();

        double basePrice = val.toObject().value("basePrice").toString().toDouble();
        int seaterNumber = val.toObject().value("seaterNumber").toString().toInt();

        int insuranceCoverage = val.toObject().value("seaterNumber").toString().toInt();
        double kmPerLitre = val.toObject().value("kmPerLitre").toString().toDouble();

        GasCar gc(vehicleID, brand, model, mileage, basePrice, seaterNumber, insuranceCoverage, kmPerLitre);
        gasCar.insert(vehicleID, gc);
    }

//    foreach(const QJsonValue & val, ptsArray){
//        gasCar[i].append(val.toObject().value("vehicleID").toString());
//        gasCar[i].append(val.toObject().value("brand").toString());
//        gasCar[i].append(val.toObject().value("model").toString());
//        gasCar[i].append(val.toObject().value("basePrice").toString());
//        gasCar[i].append(val.toObject().value("seaterNumber").toString());
//        gasCar[i].append(val.toObject().value("insuranceCoverage").toString());
//        gasCar[i].append(val.toObject().value("kmPerLitre").toString());
//        qDebug() << gasCar[i];
//        i++;
//    }

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

    foreach(const QJsonValue & val, ptsArray) {
        int vehicleID = val.toObject().value("vehicleID").toString().toInt();
        qDebug() << vehicleID;

        QString brand = val.toObject().value("brand").toString();
        QString model = val.toObject().value("model").toString();
        double mileage = val.toObject().value("mileage").toString().toDouble();

        double basePrice = val.toObject().value("basePrice").toString().toDouble();
        int insuranceCoverage = val.toObject().value("insuranceCoverage").toString().toInt();

        double pricePerCharge = val.toObject().value("pricePerCharge").toString().toDouble();
        int batteryLife = val.toObject().value("batteryLife").toString().toInt();

        double kmPerLitre = val.toObject().value("kmPerLitre").toString().toDouble();

        HybridMotorbike hb(vehicleID, brand, model, mileage, basePrice, insuranceCoverage, pricePerCharge, batteryLife, kmPerLitre);
        hybridBike.insert(vehicleID, hb);
    }

//    i =0;
//    foreach(const QJsonValue & val, ptsArray){
//        hybridBike[i].append(val.toObject().value("vehicleID").toString());
//        hybridBike[i].append(val.toObject().value("brand").toString());
//        hybridBike[i].append(val.toObject().value("model").toString());
//        hybridBike[i].append(val.toObject().value("basePrice").toString());
//        hybridBike[i].append(val.toObject().value("insuranceCoverage").toString());
//        hybridBike[i].append(val.toObject().value("pricePerCharge").toString());
//        hybridBike[i].append(val.toObject().value("batteryLife").toString());
//        hybridBike[i].append(val.toObject().value("kmPerLitre").toString());
//        hybridBike[i].append(val.toObject().value("electricPriceModifier").toString());
//        hybridBike[i].append(val.toObject().value("gasPriceModifier").toString());
//        qDebug() << hybridBike[i];
//        i++;
//    }

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

    foreach(const QJsonValue & val, ptsArray) {
        int vehicleID = val.toObject().value("vehicleID").toString().toInt();
        qDebug() << vehicleID;

        QString brand = val.toObject().value("brand").toString();
        QString model = val.toObject().value("model").toString();
        double mileage = val.toObject().value("mileage").toString().toDouble();

        double basePrice = val.toObject().value("basePrice").toString().toDouble();
        int seaterNumber = val.toObject().value("seaterNumber").toString().toInt();
        int insuranceCoverage = val.toObject().value("insuranceCoverage").toString().toInt();

        double pricePerCharge = val.toObject().value("pricePerCharge").toString().toDouble();
        int batteryLife = val.toObject().value("batteryLife").toString().toInt();

        double kmPerLitre = val.toObject().value("kmPerLitre").toString().toDouble();

        HybridCar hc(vehicleID, brand, model, mileage, basePrice, seaterNumber, insuranceCoverage, pricePerCharge, batteryLife, kmPerLitre);
        hybridCar.insert(vehicleID, hc);
    }

//    foreach(const QJsonValue & val, ptsArray){
//        hybridCar[i].append(val.toObject().value("vehicleID").toString());
//        hybridCar[i].append(val.toObject().value("brand").toString());
//        hybridCar[i].append(val.toObject().value("model").toString());
//        hybridCar[i].append(val.toObject().value("basePrice").toString());
//        hybridCar[i].append(val.toObject().value("seaterNumber").toString());
//        hybridCar[i].append(val.toObject().value("insuranceCoverage").toString());
//        hybridCar[i].append(val.toObject().value("pricePerCharge").toString());
//        hybridCar[i].append(val.toObject().value("batteryLife").toString());
//        hybridCar[i].append(val.toObject().value("kmPerLitre").toString());
//        hybridCar[i].append(val.toObject().value("electricPriceModifier").toString());
//        hybridCar[i].append(val.toObject().value("gasPriceModifier").toString());
//        qDebug() << hybridCar[i];
//        i++;
//    }

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

    foreach(const QJsonValue & val, ptsArray) {

        const QString username = val.toObject().value("userID").toString();
        const QString password = val.toObject().value("password").toString();

        User user(username, password);

        userHashMap.insert(username, user);
        userHashMap[username].printUser();
    }

    // ----------------------------------------------------------------------------
}
