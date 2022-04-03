#ifndef RenTogether_CPP
#define RenTogether_CPP

#include <iostream>
#include "RenTogether.h"
#include <QObject>
#include <QDebug>

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
Customer::Customer(int customerid, QString firstname, QString lastname, QString email) {
    this->CustomerID = customerid;
    this->FirstName = firstname;
    this->LastName = lastname;
    this->Email = email;
}

int Customer::getCustomerID(){
    return this->CustomerID;
};
QString Customer::getFirstName() {
    return this->FirstName;
};
QString Customer::getLastName(){
    return this->LastName;
};
QString Customer::getEmail(){
    return this->Email;
};

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

void Vehicle::display()
{
    qDebug() << "Vehicle Stats:";
    qDebug() << this->getVehicleID() << this->getBrand() << getModel() << getMileage();
};

QString * Vehicle::getallValues(){
    // Should never hit this function.
    static QString valuelist[4];
    int vehicleid = this->getVehicleID();
    QString brand = this->getBrand();
    QString model = this->getModel();
    double mileage = this->getMileage();
    valuelist[0]=QString::number(vehicleid);
    valuelist[1]=brand;
    valuelist[2]=model;
    valuelist[3]=QString::number(mileage)+"km";
    return valuelist;
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

void Car::display()
{
    Vehicle::display();
    qDebug() << "\nCar baseprice:";
    qDebug() << this->getBasePrice() << this->getSeaterNumber();
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

void Motorbike::display()
{
    Vehicle::display();
    qDebug() << "\nMotorbike baseprice:";
    qDebug() << this->getBasePrice();
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

QString * ElectricCar::getallValues(){
    static QString valuelist[9];
    int vehicleid = this->getVehicleID();
    QString brand = this->getBrand();
    QString model = this->getModel();
    double mileage = this->getMileage();
    double baseprice = this->getBasePrice();
    int seaternumber = this->getSeaterNumber();
    double insurance = this->getInsuranceCoverage();
    double pricepercharge = this->getPricePerCharge();
    int battery = this->getBatteryLife();
    valuelist[0]=QString::number(vehicleid);
    valuelist[1]=brand;
    valuelist[2]=model;
    valuelist[3]=QString::number(mileage)+"km";
    valuelist[4]="$"+QString::number(baseprice);
    valuelist[5]=QString::number(seaternumber);
    valuelist[6]="$"+QString::number(insurance);
    valuelist[7]="$"+QString::number(pricepercharge);
    valuelist[8]=QString::number(battery)+" hours";
    return valuelist;
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

QString * GasCar::getallValues(){
    static QString valuelist[8];
    int vehicleid = this->getVehicleID();
    QString brand = this->getBrand();
    QString model = this->getModel();
    double mileage = this->getMileage();
    double baseprice = this->getBasePrice();
    int seaternumber = this->getSeaterNumber();
    double insurance = this->getInsuranceCoverage();
    double kmperlitre = this->getkmPerLitre();
    valuelist[0]=QString::number(vehicleid);
    valuelist[1]=brand;
    valuelist[2]=model;
    valuelist[3]=QString::number(mileage)+"km";
    valuelist[4]="$"+QString::number(baseprice);
    valuelist[5]=QString::number(seaternumber);
    valuelist[6]="$"+QString::number(insurance);
    valuelist[7]=QString::number(kmperlitre)+"km per litre";
    return valuelist;
}

HybridCar::HybridCar(int vehicleid, QString brand, QString model, double mileage, double baseprice,
                     int seaternumber, int insurancecoverage, double pricepercharge,
                     int batterylife, double kmperlitre)
    : GasCar(vehicleid, brand, model, mileage, baseprice, seaternumber, insurancecoverage, kmperlitre),
      ElectricCar(vehicleid, brand, model, mileage, baseprice, seaternumber, insurancecoverage, pricepercharge, batterylife){};

ElectricMotorbike::ElectricMotorbike(int vehicleid, QString brand, QString model, double mileage,
                                     double baseprice, int insurancecoverage, double pricepercharge, int batterylife)
{
    Motorbike::setvalues(vehicleid, brand, model, mileage, baseprice, insurancecoverage);
    this->BatteryLife = batterylife;
    this->PricePerCharge = pricepercharge;
};

QString * HybridCar::getallValues(){
    static QString valuelist[10];
    int vehicleid = this->getVehicleID();
    QString brand = this->getBrand();
    QString model = this->getModel();
    double mileage = this->getMileage();
    double baseprice = this->getBasePrice();
    int seaternumber = this->getSeaterNumber();
    double insurance = this->getInsuranceCoverage();
    double pricepercharge = this->getPricePerCharge();
    int battery = this->getBatteryLife();
    double kmperlitre = this->getkmPerLitre();
    valuelist[0]=QString::number(vehicleid);
    valuelist[1]=brand;
    valuelist[2]=model;
    valuelist[3]=QString::number(mileage)+"km";
    valuelist[4]="$"+QString::number(baseprice);
    valuelist[5]=QString::number(seaternumber);
    valuelist[6]="$"+QString::number(insurance);
    valuelist[7]="$"+QString::number(pricepercharge);
    valuelist[8]=QString::number(battery)+" hours";
    valuelist[9]=QString::number(kmperlitre)+"km per litre";
    return valuelist;
}

double ElectricMotorbike::getPricePerCharge()
{
    return this->PricePerCharge;
};

int ElectricMotorbike::getBatteryLife()
{
    return this->BatteryLife;
};

QString * ElectricMotorbike::getallValues(){
    static QString valuelist[8];
    int vehicleid = this->getVehicleID();
    QString brand = this->getBrand();
    QString model = this->getModel();
    double mileage = this->getMileage();
    double baseprice = this->getBasePrice();
    double insurance = this->getInsuranceCoverage();
    double pricepercharge = this->getPricePerCharge();
    int battery = this->getBatteryLife();
    valuelist[0]=QString::number(vehicleid);
    valuelist[1]=brand;
    valuelist[2]=model;
    valuelist[3]=QString::number(mileage)+"km";
    valuelist[4]="$"+QString::number(baseprice);
    valuelist[5]="$"+QString::number(insurance);
    valuelist[6]="$"+QString::number(pricepercharge);
    valuelist[7]=QString::number(battery)+" hours";
    return valuelist;
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

QString * GasMotorbike::getallValues(){
    static QString valuelist[7];
    int vehicleid = this->getVehicleID();
    QString brand = this->getBrand();
    QString model = this->getModel();
    double mileage = this->getMileage();
    double baseprice = this->getBasePrice();
    double insurance = this->getInsuranceCoverage();
    double kmperlitre = this->getkmPerLitre();
    valuelist[0]=QString::number(vehicleid);
    valuelist[1]=brand;
    valuelist[2]=model;
    valuelist[3]=QString::number(mileage)+"km";
    valuelist[4]="$"+QString::number(baseprice);
    valuelist[5]="$"+QString::number(insurance);
    valuelist[6]=QString::number(kmperlitre)+"km per litre";
    return valuelist;
}

HybridMotorbike::HybridMotorbike(int vehicleid, QString brand, QString model, double mileage, double baseprice,
                                 int insurancecoverage, double pricepercharge, int batterylife, double kmperlitre)
    : GasMotorbike(vehicleid, brand, model, mileage, baseprice, insurancecoverage, kmperlitre),
      ElectricMotorbike(vehicleid, brand, model, mileage, baseprice, insurancecoverage, pricepercharge, batterylife){};

QString * HybridMotorbike::getallValues(){
    static QString valuelist[9];
    int vehicleid = this->getVehicleID();
    QString brand = this->getBrand();
    QString model = this->getModel();
    double mileage = this->getMileage();
    double baseprice = this->getBasePrice();
    double insurance = this->getInsuranceCoverage();
    double pricepercharge = this->getPricePerCharge();
    int battery = this->getBatteryLife();
    double kmperlitre = this->getkmPerLitre();
    valuelist[0]=QString::number(vehicleid);
    valuelist[1]=brand;
    valuelist[2]=model;
    valuelist[3]=QString::number(mileage)+"km";
    valuelist[4]="$"+QString::number(baseprice);
    valuelist[5]="$"+QString::number(insurance);
    valuelist[6]="$"+QString::number(pricepercharge);
    valuelist[7]=QString::number(battery)+" hours";
    valuelist[8]=QString::number(kmperlitre)+"km per litre";
    return valuelist;
}

#endif
