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

//Vehicle List -------------------------------------------------------
QVector<Vehicle*> jsonReader::getVehicleList() {
    return this->vehicleList;
}

int jsonReader::getVehicleCounter() {
    return this->vehiclecounter;
}

void jsonReader::setvehicleCounter(int counter) {
    this->vehiclecounter = counter;
}
//--------------------------------------------------------------------


//Customer List -------------------------------------------------------
QVector<Customer*> jsonReader::getCustomerList()
{
    return this->customerList;
}

Customer* jsonReader::getCurrentCustomer() {
    return this->currentCustomer;
}

void jsonReader::setCurrentCustomer(Customer *currentCustomer) {
    this->currentCustomer = currentCustomer;
}
//--------------------------------------------------------------------


//Rental List -------------------------------------------------------
QVector<Rental*> jsonReader::getRentalList(){
    return this->rentalList;
};

void jsonReader::setRentalList(QVector<Rental*> rentallist){
     this->rentalList = rentallist;
}
//--------------------------------------------------------------------



jsonReader::jsonReader()
{
    int vehiclecount = 0;

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
        QString brand = val.toObject().value("brand").toString();
        QString model = val.toObject().value("model").toString();
        double mileage = val.toObject().value("mileage").toString().toDouble();
        double basePrice = val.toObject().value("basePrice").toString().toDouble();
        int insuranceCoverage = val.toObject().value("insuranceCoverage").toString().toInt();

        double pricePerCharge = val.toObject().value("pricePerCharge").toString().toDouble();
        int batteryLife = val.toObject().value("batteryLife").toString().toInt();

        this->vehicleList.push_back(new ElectricMotorbike(vehicleID, brand, model, mileage, basePrice, insuranceCoverage, pricePerCharge, batteryLife));
        vehiclecount++;
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

    foreach(const QJsonValue & val, ptsArray) {
        int vehicleID = val.toObject().value("vehicleID").toString().toInt();

        QString brand = val.toObject().value("brand").toString();
        QString model = val.toObject().value("model").toString();
        double mileage = val.toObject().value("mileage").toString().toDouble();

        double basePrice = val.toObject().value("basePrice").toString().toDouble();
        int seaterNumber = val.toObject().value("seaterNumber").toString().toInt();

        int insuranceCoverage = val.toObject().value("insuranceCoverage").toString().toInt();
        double pricePerCharge = val.toObject().value("pricePerCharge").toString().toDouble();
        int batteryLife = val.toObject().value("batteryLife").toString().toInt();

        ElectricCar ec(vehicleID, brand, model, mileage, basePrice, seaterNumber, insuranceCoverage, pricePerCharge, batteryLife);
        this->vehicleList.push_back(new ElectricCar(vehicleID, brand, model, mileage, basePrice, seaterNumber, insuranceCoverage, pricePerCharge, batteryLife));
        vehiclecount++;
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

    foreach(const QJsonValue & val, ptsArray) {
        int vehicleID = val.toObject().value("vehicleID").toString().toInt();

        QString brand = val.toObject().value("brand").toString();
        QString model = val.toObject().value("model").toString();
        double mileage = val.toObject().value("mileage").toString().toDouble();

        double basePrice = val.toObject().value("basePrice").toString().toDouble();
        int insuranceCoverage = val.toObject().value("insuranceCoverage").toString().toInt();

        double kmPerLitre = val.toObject().value("kmPerLitre").toString().toDouble();

        GasMotorbike gb(vehicleID, brand, model, mileage, basePrice, insuranceCoverage, kmPerLitre);
        this->vehicleList.push_back(new GasMotorbike(vehicleID, brand, model, mileage, basePrice, insuranceCoverage, kmPerLitre));
        vehiclecount++;
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

    foreach(const QJsonValue & val, ptsArray) {
        int vehicleID = val.toObject().value("vehicleID").toString().toInt();

        QString brand = val.toObject().value("brand").toString();
        QString model = val.toObject().value("model").toString();
        double mileage = val.toObject().value("mileage").toString().toDouble();

        double basePrice = val.toObject().value("basePrice").toString().toDouble();
        int seaterNumber = val.toObject().value("seaterNumber").toString().toInt();

        int insuranceCoverage = val.toObject().value("insuranceCoverage").toString().toInt();
        double kmPerLitre = val.toObject().value("kmPerLitre").toString().toDouble();

        this->vehicleList.push_back(new GasCar(vehicleID, brand, model, mileage, basePrice, seaterNumber, insuranceCoverage, kmPerLitre));
        vehiclecount++;
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

    foreach(const QJsonValue & val, ptsArray) {
        int vehicleID = val.toObject().value("vehicleID").toString().toInt();

        QString brand = val.toObject().value("brand").toString();
        QString model = val.toObject().value("model").toString();
        double mileage = val.toObject().value("mileage").toString().toDouble();

        double basePrice = val.toObject().value("basePrice").toString().toDouble();
        int insuranceCoverage = val.toObject().value("insuranceCoverage").toString().toInt();

        double pricePerCharge = val.toObject().value("pricePerCharge").toString().toDouble();
        int batteryLife = val.toObject().value("batteryLife").toString().toInt();

        double kmPerLitre = val.toObject().value("kmPerLitre").toString().toDouble();

        this->vehicleList.push_back(new HybridMotorbike(vehicleID, brand, model, mileage, basePrice, insuranceCoverage, pricePerCharge, batteryLife, kmPerLitre));
        vehiclecount++;
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

    foreach(const QJsonValue & val, ptsArray) {
        int vehicleID = val.toObject().value("vehicleID").toString().toInt();

        QString brand = val.toObject().value("brand").toString();
        QString model = val.toObject().value("model").toString();
        double mileage = val.toObject().value("mileage").toString().toDouble();

        double basePrice = val.toObject().value("basePrice").toString().toDouble();
        int seaterNumber = val.toObject().value("seaterNumber").toString().toInt();
        int insuranceCoverage = val.toObject().value("insuranceCoverage").toString().toInt();

        double pricePerCharge = val.toObject().value("pricePerCharge").toString().toDouble();
        int batteryLife = val.toObject().value("batteryLife").toString().toInt();

        double kmPerLitre = val.toObject().value("kmPerLitre").toString().toDouble();

        this->vehicleList.push_back(new HybridCar(vehicleID, brand, model, mileage, basePrice, seaterNumber, insuranceCoverage, pricePerCharge, batteryLife, kmPerLitre));
        vehiclecount++;
    }

    // Set the vehicle count
    setvehicleCounter(vehiclecount);

    // ----------------------------------------------------------------------------

    QFile inFile7(":/data/data/customer.json");
    inFile7.open(QIODevice::ReadOnly | QIODevice::Text);
    data = inFile7.readAll();
    inFile7.close();

    doc = QJsonDocument::fromJson(data, &errorPtr);
    if (doc.isNull()) {
       qDebug() << "Parse failed";
    }
    rootObj = doc.object();
    ptsArray = rootObj.value("customer").toArray();

    foreach(const QJsonValue & val, ptsArray) {

        const int customerID = val.toObject().value("CustomerID").toString().toInt();
        const QString FirstName = val.toObject().value("FirstName").toString();
        const QString LastName = val.toObject().value("LastName").toString();
        const QString Email = val.toObject().value("Email").toString();
        const QString username = val.toObject().value("Username").toString();
        const QString hash = val.toObject().value("Hash").toString();

        this->customerList.push_back(new Customer(customerID, FirstName, LastName, Email, username, hash));

    }


    // ----------------------------------------------------------------------------

    QFile inFile8(":/data/data/rental.json");
    inFile8.open(QIODevice::ReadOnly | QIODevice::Text);
    data = inFile8.readAll();
    inFile8.close();

    doc = QJsonDocument::fromJson(data, &errorPtr);
    if (doc.isNull()) {
       qDebug() << "Parse failed";
    }
    rootObj = doc.object();
    ptsArray = rootObj.value("rental").toArray();
    foreach(const QJsonValue & val, ptsArray) {
        int rentalID = val.toObject().value("rentalID").toString().toInt();
        int CustomerID = val.toObject().value("CustomerID").toString().toInt();
        int VehicleID = val.toObject().value("VehicleID").toString().toInt();
        const QString StartDate = val.toObject().value("StartDate").toString();
        const QString EndDate = val.toObject().value("EndDate").toString();
        int RentDuration = val.toObject().value("RentDuration").toString().toInt();
        double Price = val.toObject().value("Price").toString().toDouble();
        this->rentalList.push_back(new Rental(rentalID, CustomerID, VehicleID, StartDate, EndDate, RentDuration, Price));
    }

}
