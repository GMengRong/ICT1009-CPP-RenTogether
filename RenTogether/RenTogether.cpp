#ifndef RenTogether_CPP
#define RenTogether_CPP

#include <iostream>
#include "RenTogether.h"
#include <QObject>
#include <QDebug>
#include <QMap>

// Rental functions
Rental::Rental(int rentalid, int customerid, int vehicleid, QString startdate,
QString enddate, int rentduration, double price){
    this->rentalID = rentalid;
    this->CustomerID = customerid;
    this->VehicleID = vehicleid;
    this->StartDate = startdate;
    this->EndDate = enddate;
    this->RentDuration = rentduration;
    this->Price = price;
};

int Rental::getrentalID(){
    return this->rentalID;
};
int Rental::getCustomerID(){
    return this->CustomerID;
};
int Rental::getVehicleID(){
    return this->VehicleID;
};
QString Rental::getStartDate(){
    return this->StartDate;
};
QString Rental::getEndDate(){
    return this->EndDate;
};
double Rental::getprice(){
    return this->Price;
};

// Customer functions
Customer::Customer(int customerid, QString firstname, QString lastname, QString email, QString username, QString hash) {
    this->CustomerID = customerid;
    this->FirstName = firstname;
    this->LastName = lastname;
    this->Email = email;

    this->username = username;
    this->hash = hash;
}

int Customer::getCustomerID(){
    return this->CustomerID;
}
QString Customer::getFirstName() {
    return this->FirstName;
}
QString Customer::getLastName(){
    return this->LastName;
}
QString Customer::getEmail(){
    return this->Email;
}
QString Customer::getUsername()
{
    return this->username;
}
QString Customer::getHash()
{
    return this->hash;
}
void Customer::printUser()
{
    qDebug() << getUsername() << getHash();
}

// Vehicle functions
void Vehicle::setvalues(int id, QString brand, QString model, double mileage)
{
    this->VehicleID = id;
    this->Brand = brand;
    this->Model = model;
    this->Mileage = mileage;
}

int Vehicle::getVehicleID()
{
    return this->VehicleID;
};

QString Vehicle::getBrand()
{
    return this->Brand;
};

QString Vehicle::getModel()
{
    return this->Model;
};

double Vehicle::getMileage()
{
    return this->Mileage;
};

QString Vehicle::getVehicleType(){
    // Should never hit this function.
    return "defaultvehicle";
}

QMap<QString,QString> Vehicle::getallValues(){
    // Should never hit this function.
    QMap<QString,QString> vehicledetailsmap;
    return vehicledetailsmap;
}

double Vehicle::getBasePrice(){
    // Should never hit this function.
    return 0;
}

// Car functions
void Car::setvalues(int vehicleid, QString brand, QString model, double mileage,
                    double baseprice, int seaternumber, int insurancecoverage)
{
    Vehicle::setvalues(vehicleid, brand, model, mileage);
    this->BasePrice = baseprice;
    this->SeaterNumber = seaternumber;
    this->InsuranceCoverage = insurancecoverage;
};

double Car::getBasePrice()
{
    return this->BasePrice;
};

int Car::getSeaterNumber()
{
    return this->SeaterNumber;
};

int Car::getInsuranceCoverage()
{
    return this->InsuranceCoverage;
};

// Motorbike functions
void Motorbike::setvalues(int vehicleid, QString brand, QString model, double mileage,
                          double baseprice, int insurancecoverage)
{
    Vehicle::setvalues(vehicleid, brand, model, mileage);
    this->BasePrice = baseprice;
    this->InsuranceCoverage = insurancecoverage;
}

double Motorbike::getBasePrice()
{
    return this->BasePrice;
};

int Motorbike::getInsuranceCoverage()
{
    return this->InsuranceCoverage;
};

// Functions for the 6 different vehicle types
ElectricCar::ElectricCar(int vehicleid, QString brand, QString model, double mileage,
                         double baseprice, int seaternumber, int insurancecoverage, double pricepercharge, int batterylife)
{
    Car::setvalues(vehicleid, brand, model, mileage, baseprice, seaternumber, insurancecoverage);
    this->PricePerCharge = pricepercharge;
    this->BatteryLife = batterylife;
}

double ElectricCar::getPricePerCharge()
{
    return this->PricePerCharge;
};

int ElectricCar::getBatteryLife()
{
    return this->BatteryLife;
};

QString ElectricCar::getVehicleType(){
    return "ElectricCar";
}

QMap<QString,QString> ElectricCar::getallValues(){
    QMap<QString,QString> vehicledetailmap;

    QString vehicleid = QString::number(this->getVehicleID());
    QString brand = this->getBrand();
    QString model = this->getModel();
    QString mileage = QString::number(this->getMileage());
    QString baseprice = QString::number(this->getBasePrice());
    QString seaternumber = QString::number(this->getSeaterNumber());
    QString insurance = QString::number(this->getInsuranceCoverage());
    QString pricepercharge = QString::number(this->getPricePerCharge());
    QString battery = QString::number(this->getBatteryLife());

    vehicledetailmap.insert("VehicleID",vehicleid);
    vehicledetailmap.insert("Brand",brand);
    vehicledetailmap.insert("Model",model);
    vehicledetailmap.insert("Mileage",mileage);
    vehicledetailmap.insert("BasePrice",baseprice);
    vehicledetailmap.insert("SeaterNumber",seaternumber);
    vehicledetailmap.insert("InsuranceCoverage",insurance);
    vehicledetailmap.insert("PricePerCharge",pricepercharge);
    vehicledetailmap.insert("BatteryLife",battery);
    return vehicledetailmap;
}

GasCar::GasCar(int vehicleid, QString brand, QString model, double mileage,
               double baseprice, int seaternumber, int insurancecoverage, double kmperlitre)
{
    Car::setvalues(vehicleid, brand, model, mileage, baseprice, seaternumber, insurancecoverage);
    this->kmPerLitre = kmperlitre;
}

double GasCar::getkmPerLitre() {
    return this->kmPerLitre;
}

QString GasCar::getVehicleType(){
    return "GasCar";
}

QMap<QString,QString> GasCar::getallValues(){
    QMap<QString,QString> vehicledetailmap;

    QString vehicleid = QString::number(this->getVehicleID());
    QString brand = this->getBrand();
    QString model = this->getModel();
    QString mileage = QString::number(this->getMileage());
    QString baseprice = QString::number(this->getBasePrice());
    QString seaternumber = QString::number(this->getSeaterNumber());
    QString insurance = QString::number(this->getInsuranceCoverage());
    QString kmperlitre = QString::number(this->getkmPerLitre());

    vehicledetailmap.insert("VehicleID",vehicleid);
    vehicledetailmap.insert("Brand",brand);
    vehicledetailmap.insert("Model",model);
    vehicledetailmap.insert("Mileage",mileage);
    vehicledetailmap.insert("BasePrice",baseprice);
    vehicledetailmap.insert("SeaterNumber",seaternumber);
    vehicledetailmap.insert("InsuranceCoverage",insurance);
    vehicledetailmap.insert("KmPerLitre",kmperlitre);

    return vehicledetailmap;
}

HybridCar::HybridCar(int vehicleid, QString brand, QString model, double mileage, double baseprice,
                     int seaternumber, int insurancecoverage, double pricepercharge,
                     int batterylife, double kmperlitre)
    : GasCar(vehicleid, brand, model, mileage, baseprice, seaternumber, insurancecoverage, kmperlitre),
      ElectricCar(vehicleid, brand, model, mileage, baseprice, seaternumber, insurancecoverage, pricepercharge, batterylife){};

QString HybridCar::getVehicleType(){
    return "HybridCar";
}

QMap<QString,QString> HybridCar::getallValues(){
    QMap<QString,QString> vehicledetailmap;

    QString vehicleid = QString::number(this->getVehicleID());
    QString brand = this->getBrand();
    QString model = this->getModel();
    QString mileage = QString::number(this->getMileage());
    QString baseprice = QString::number(this->getBasePrice());
    QString seaternumber = QString::number(this->getSeaterNumber());
    QString insurance = QString::number(this->getInsuranceCoverage());
    QString pricepercharge = QString::number(this->getPricePerCharge());
    QString battery = QString::number(this->getBatteryLife());
    QString kmperlitre = QString::number(this->getkmPerLitre());

    vehicledetailmap.insert("VehicleID",vehicleid);
    vehicledetailmap.insert("Brand",brand);
    vehicledetailmap.insert("Model",model);
    vehicledetailmap.insert("Mileage",mileage);
    vehicledetailmap.insert("BasePrice",baseprice);
    vehicledetailmap.insert("SeaterNumber",seaternumber);
    vehicledetailmap.insert("InsuranceCoverage",insurance);
    vehicledetailmap.insert("PricePerCharge",pricepercharge);
    vehicledetailmap.insert("BatteryLife",battery);
    vehicledetailmap.insert("KmPerLitre",kmperlitre);

    return vehicledetailmap;
}

ElectricMotorbike::ElectricMotorbike(int vehicleid, QString brand, QString model, double mileage,
                                     double baseprice, int insurancecoverage, double pricepercharge, int batterylife)
{
    Motorbike::setvalues(vehicleid, brand, model, mileage, baseprice, insurancecoverage);
    this->BatteryLife = batterylife;
    this->PricePerCharge = pricepercharge;
};


double ElectricMotorbike::getPricePerCharge()
{
    return this->PricePerCharge;
};

int ElectricMotorbike::getBatteryLife()
{
    return this->BatteryLife;
};

QString ElectricMotorbike::getVehicleType(){
    return "ElectricMotorbike";
}

QMap<QString,QString> ElectricMotorbike::getallValues(){
    QMap<QString,QString> vehicledetailmap;

    QString vehicleid = QString::number(this->getVehicleID());
    QString brand = this->getBrand();
    QString model = this->getModel();
    QString mileage = QString::number(this->getMileage());
    QString baseprice = QString::number(this->getBasePrice());
    QString insurance = QString::number(this->getInsuranceCoverage());
    QString pricepercharge = QString::number(this->getPricePerCharge());
    QString battery = QString::number(this->getBatteryLife());

    vehicledetailmap.insert("VehicleID",vehicleid);
    vehicledetailmap.insert("Brand",brand);
    vehicledetailmap.insert("Model",model);
    vehicledetailmap.insert("Mileage",mileage);
    vehicledetailmap.insert("BasePrice",baseprice);
    vehicledetailmap.insert("InsuranceCoverage",insurance);
    vehicledetailmap.insert("PricePerCharge",pricepercharge);
    vehicledetailmap.insert("BatteryLife",battery);

    return vehicledetailmap;
}

GasMotorbike::GasMotorbike(int vehicleid, QString brand, QString model, double mileage,
                           double baseprice, int insurancecoverage, double kmperlitre)
{
    Motorbike::setvalues(vehicleid, brand, model, mileage, baseprice, insurancecoverage);
    this->kmPerLitre = kmperlitre;
};

double GasMotorbike::getkmPerLitre()
{
    return this->kmPerLitre;
};

QString GasMotorbike::getVehicleType(){
    return "GasMotorbike";
}


QMap<QString,QString> GasMotorbike::getallValues(){
    QMap<QString,QString> vehicledetailmap;

    QString vehicleid = QString::number(this->getVehicleID());
    QString brand = this->getBrand();
    QString model = this->getModel();
    QString mileage = QString::number(this->getMileage());
    QString baseprice = QString::number(this->getBasePrice());
    QString insurance = QString::number(this->getInsuranceCoverage());
    QString kmperlitre = QString::number(this->getkmPerLitre());

    vehicledetailmap.insert("VehicleID",vehicleid);
    vehicledetailmap.insert("Brand",brand);
    vehicledetailmap.insert("Model",model);
    vehicledetailmap.insert("Mileage",mileage);
    vehicledetailmap.insert("BasePrice",baseprice);
    vehicledetailmap.insert("InsuranceCoverage",insurance);
    vehicledetailmap.insert("KmPerLitre",kmperlitre);

    return vehicledetailmap;
}

HybridMotorbike::HybridMotorbike(int vehicleid, QString brand, QString model, double mileage, double baseprice,
                                 int insurancecoverage, double pricepercharge, int batterylife, double kmperlitre)
    : GasMotorbike(vehicleid, brand, model, mileage, baseprice, insurancecoverage, kmperlitre),
      ElectricMotorbike(vehicleid, brand, model, mileage, baseprice, insurancecoverage, pricepercharge, batterylife){};

QString HybridMotorbike::getVehicleType(){
    return "HybridMotorbike";
}

QMap<QString,QString>  HybridMotorbike::getallValues(){
    QMap<QString,QString> vehicledetailmap;

    QString vehicleid = QString::number(this->getVehicleID());
    QString brand = this->getBrand();
    QString model = this->getModel();
    QString mileage = QString::number(this->getMileage());
    QString baseprice = QString::number(this->getBasePrice());
    QString insurance = QString::number(this->getInsuranceCoverage());
    QString pricepercharge = QString::number(this->getPricePerCharge());
    QString battery = QString::number(this->getBatteryLife());
    QString kmperlitre = QString::number(this->getkmPerLitre());

    vehicledetailmap.insert("VehicleID",vehicleid);
    vehicledetailmap.insert("Brand",brand);
    vehicledetailmap.insert("Model",model);
    vehicledetailmap.insert("Mileage",mileage);
    vehicledetailmap.insert("BasePrice",baseprice);
    vehicledetailmap.insert("InsuranceCoverage",insurance);
    vehicledetailmap.insert("PricePerCharge",pricepercharge);
    vehicledetailmap.insert("BatteryLife",battery);
    vehicledetailmap.insert("KmPerLitre",kmperlitre);

    return vehicledetailmap;
}

#endif
