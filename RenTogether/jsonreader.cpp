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
#include <QCoreApplication>
#include <iostream>
#include <QMessageBox>

#include "jsonreader.h"

const QString ERROR_MSG = "Import failed! File does not exists or did not open properly";
const QString JSON_ERROR ="Parsing error! Missing object header, check file data formatting";

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

// declare variables
QJsonDocument doc;
QJsonArray ptsArray;
QByteArray data;
QJsonParseError errorPtr;
QJsonObject rootObj;
QFile inFile;

jsonReader::jsonReader(){}

int jsonReader::initialiseLists()
{

    QWidget *window = nullptr;

    int vehiclecount = 0;
    QString dirPath = QCoreApplication::applicationDirPath();
    QString errorFile = NULL;

    // try to open json file. if fail, catch error and display error messsage in terminal
    try {

        QFile inFile(dirPath + "/../data/electricBike.json");
        if (!inFile.open(QIODevice::ReadOnly | QIODevice::Text)) {
            errorFile = "electricBike.json";
            throw(1); // if file cannot be read/empty
        }

        data = inFile.readAll();
        inFile.close();

        doc = QJsonDocument::fromJson(data, &errorPtr);
        rootObj = doc.object();
        ptsArray = rootObj.value("electricBike").toArray();

        if (ptsArray.isEmpty()){
            errorFile = "electricBike.json";
            throw(2); // if cannot find object header in file
        }

        // loop through each item within the json file and store values in variables
        foreach(const QJsonValue & val, ptsArray) {
            int vehicleID = val.toObject().value("vehicleID").toString().toInt();
            QString brand = val.toObject().value("brand").toString();
            QString model = val.toObject().value("model").toString();
            double mileage = val.toObject().value("mileage").toString().toDouble();
            double basePrice = val.toObject().value("basePrice").toString().toDouble();
            int insuranceCoverage = val.toObject().value("insuranceCoverage").toString().toInt();

            double pricePerCharge = val.toObject().value("pricePerCharge").toString().toDouble();
            int batteryLife = val.toObject().value("batteryLife").toString().toInt();

            // create objects with the variables and store object into vectors.
            this->vehicleList.push_back(new ElectricMotorbike(vehicleID, brand, model, mileage, basePrice, insuranceCoverage, pricePerCharge, batteryLife));
            vehiclecount++;
        }

    // ----------------------------------------------------------------------------

        // try to open json file. if fail, catch error and display error messsage in terminal

        QFile inFile2(dirPath + "/../data/electricCar.json");

        if (!inFile2.open(QIODevice::ReadOnly | QIODevice::Text)) {
            errorFile = "electricCar.json";
            throw(1); // if file cannot be read/empty
        }

        data = inFile2.readAll();
        inFile2.close();

        doc = QJsonDocument::fromJson(data, &errorPtr);
        rootObj = doc.object();
        ptsArray = rootObj.value("electricCar").toArray();

        if (ptsArray.isEmpty()){
            errorFile = "electricCar.json";
            throw(2); // if cannot find object header in file
        }

        // loop through each item within the json file and store values in variables
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
            // create objects with the variables and store object into vectors.
            this->vehicleList.push_back(new ElectricCar(vehicleID, brand, model, mileage, basePrice, seaterNumber, insuranceCoverage, pricePerCharge, batteryLife));
            vehiclecount++;
        }

    // ----------------------------------------------------------------------------

        QFile inFile3(dirPath + "/../data/gasBike.json");

        if (!inFile3.open(QIODevice::ReadOnly | QIODevice::Text)) {
            errorFile = "gasBike.json";
            throw(1); // if file cannot be read/empty
        }

        data = inFile3.readAll();
        inFile3.close();

        doc = QJsonDocument::fromJson(data, &errorPtr);
        rootObj = doc.object();
        ptsArray = rootObj.value("gasBike").toArray();

        if (ptsArray.isEmpty()){
            errorFile = "gasBike.json";
            throw(2); // if cannot find object header in file
        }

        // loop through each item within the json file and store values in variables
        foreach(const QJsonValue & val, ptsArray) {
            int vehicleID = val.toObject().value("vehicleID").toString().toInt();

            QString brand = val.toObject().value("brand").toString();
            QString model = val.toObject().value("model").toString();
            double mileage = val.toObject().value("mileage").toString().toDouble();
            double basePrice = val.toObject().value("basePrice").toString().toDouble();
            int insuranceCoverage = val.toObject().value("insuranceCoverage").toString().toInt();
            double kmPerLitre = val.toObject().value("kmPerLitre").toString().toDouble();

            GasMotorbike gb(vehicleID, brand, model, mileage, basePrice, insuranceCoverage, kmPerLitre);
            // create objects with the variables and store object into vectors.
            this->vehicleList.push_back(new GasMotorbike(vehicleID, brand, model, mileage, basePrice, insuranceCoverage, kmPerLitre));
            vehiclecount++;
        }

    // ----------------------------------------------------------------------------

        QFile inFile4(dirPath + "/../data/gasCar.json");
        if (!inFile4.open(QIODevice::ReadOnly | QIODevice::Text)) {
            errorFile = "gasCar.json";
            throw(1); // if file cannot be read/empty
        }

        data = inFile4.readAll();
        inFile4.close();

        doc = QJsonDocument::fromJson(data, &errorPtr);
        rootObj = doc.object();
        ptsArray = rootObj.value("gasCar").toArray();

        if (ptsArray.isEmpty()){
            errorFile = "gasCar.json";
            throw(2); // if cannot find object header in file
        }

        // loop through each item within the json file and store values in variables
        foreach(const QJsonValue & val, ptsArray) {
            int vehicleID = val.toObject().value("vehicleID").toString().toInt();
            QString brand = val.toObject().value("brand").toString();
            QString model = val.toObject().value("model").toString();
            double mileage = val.toObject().value("mileage").toString().toDouble();
            double basePrice = val.toObject().value("basePrice").toString().toDouble();
            int seaterNumber = val.toObject().value("seaterNumber").toString().toInt();
            int insuranceCoverage = val.toObject().value("insuranceCoverage").toString().toInt();
            double kmPerLitre = val.toObject().value("kmPerLitre").toString().toDouble();

            // create objects with the variables and store object into vectors.
            this->vehicleList.push_back(new GasCar(vehicleID, brand, model, mileage, basePrice, seaterNumber, insuranceCoverage, kmPerLitre));
            vehiclecount++;
        }

        // ----------------------------------------------------------------------------

        QFile inFile5(dirPath + "/../data/hybridBike.json");
        if (!inFile5.open(QIODevice::ReadOnly | QIODevice::Text)) {
            errorFile = "hybridBike.json";
            throw(1); // if file cannot be read/empty
        }
        data = inFile5.readAll();
        inFile5.close();

        doc = QJsonDocument::fromJson(data, &errorPtr);
        rootObj = doc.object();
        ptsArray = rootObj.value("hybridBike").toArray();

        if (ptsArray.isEmpty()){
            errorFile = "hybridBike.json";
            throw(2); // if cannot find object header in file
        }

        // loop through each item within the json file and store values in variables
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

            // create objects with the variables and store object into vectors.
            this->vehicleList.push_back(new HybridMotorbike(vehicleID, brand, model, mileage, basePrice, insuranceCoverage, pricePerCharge, batteryLife, kmPerLitre));
            vehiclecount++;
        }

    // ----------------------------------------------------------------------------

        QFile inFile6(dirPath + "/../data/hybridCar.json");
        if (!inFile6.open(QIODevice::ReadOnly | QIODevice::Text)) {
            errorFile = "hybridCar.json";
            throw(1); // if file cannot be read/empty
        }
        data = inFile6.readAll();
        inFile6.close();

        doc = QJsonDocument::fromJson(data, &errorPtr);
        rootObj = doc.object();
        ptsArray = rootObj.value("hybridCar").toArray();

        // check to see if json file in correct format
        if (ptsArray.isEmpty()){
            errorFile = "hybridCar.json";
            throw(2); // if cannot find object header in file
        }

        // loop through each item within the json file and store values in variables
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

            // create objects with the variables and store object into vectors.
            this->vehicleList.push_back(new HybridCar(vehicleID, brand, model, mileage, basePrice, seaterNumber, insuranceCoverage, pricePerCharge, batteryLife, kmPerLitre));
            vehiclecount++;
        }

        // Set the vehicle count
        setvehicleCounter(vehiclecount);

        // ----------------------------------------------------------------------------

        QFile inFile7(dirPath + "/../data/customer.json");
        if (!inFile7.open(QIODevice::ReadOnly | QIODevice::Text)) {
            errorFile = "customer.json";
            throw(1); // if file cannot be read/empty
        }
        data = inFile7.readAll();
        inFile7.close();

        doc = QJsonDocument::fromJson(data, &errorPtr);
        rootObj = doc.object();
        ptsArray = rootObj.value("customer").toArray();

        // check to see if json file in correct format
        if (ptsArray.isEmpty()){
            errorFile = "customer.json";
            throw(2); // if cannot find object header in file
        }

        // loop through each item within the json file and store values in variables
        foreach(const QJsonValue & val, ptsArray) {

            const int customerID = val.toObject().value("CustomerID").toString().toInt();
            const QString FirstName = val.toObject().value("FirstName").toString();
            const QString LastName = val.toObject().value("LastName").toString();
            const QString Email = val.toObject().value("Email").toString();
            const QString username = val.toObject().value("Username").toString();
            const QString hash = val.toObject().value("Hash").toString();

            // create objects with the variables and store object into vectors.
            this->customerList.push_back(new Customer(customerID, FirstName, LastName, Email, username, hash));
        }

        // ----------------------------------------------------------------------------

        QFile inFile8(dirPath + "/../data/rental.json");
        if (!inFile8.open(QIODevice::ReadOnly | QIODevice::Text)) {
            errorFile = "rental.json";
            throw(1); // if file cannot be read/empty
        }
        data = inFile8.readAll();
        inFile8.close();

        doc = QJsonDocument::fromJson(data, &errorPtr);
        rootObj = doc.object();
        ptsArray = rootObj.value("rental").toArray();

        // check to see if json file in correct format
        if (ptsArray.isEmpty()){
            errorFile = "rental.json";
            throw(2); // if cannot find object header in file
        }

        // loop through each item within the json file and store values in variables
        foreach(const QJsonValue & val, ptsArray) {
            int rentalID = val.toObject().value("rentalID").toString().toInt();
            int CustomerID = val.toObject().value("CustomerID").toString().toInt();
            int VehicleID = val.toObject().value("VehicleID").toString().toInt();
            const QString StartDate = val.toObject().value("StartDate").toString();
            const QString EndDate = val.toObject().value("EndDate").toString();
            int RentDuration = val.toObject().value("RentDuration").toString().toInt();
            double Price = val.toObject().value("Price").toString().toDouble();

            // create objects with the variables and store object into vectors.
            this->rentalList.push_back(new Rental(rentalID, CustomerID, VehicleID, StartDate, EndDate, RentDuration, Price));
        }

    } catch (int error){
        if (error ==1)
        {
            QMessageBox::warning(window,"Import Error in " + errorFile, ERROR_MSG);
        }
        else
        {
            QMessageBox::warning(window,"Import Error in " + errorFile, JSON_ERROR);
        }
        return 1;
    }
    return 0;
}
