#ifndef RenTogether_H
#define RenTogether_H
#include <QObject>

// Forward declaration
class Customer;
class Vehicle;


class Rental
{
private:
    int rentalID;
    int CustomerID;
    int VehicleID;
    QString StartDate;
    QString EndDate;
    int RentDuration;
    double Price;

public:
    Rental(int, int, int, QString, QString, int, double);
    int getrentalID();
    int getCustomerID();
    int getVehicleID();
    QString getStartDate();
    QString getEndDate();
    double getprice();
};

class Customer
{
private:
    int CustomerID;
    QString FirstName;
    QString LastName;
    QString Email;

public:
    Customer(int, QString, QString, QString);
    int getCustomerID();
    QString getFirstName();
    QString getLastName();
    QString getEmail();
};

class Vehicle
{
private:
    int VehicleID;
    QString Brand;
    QString Model;
    double Mileage;

public:
    void setvalues(int, QString, QString, double);
    int getVehicleID();
    QString getBrand();
    QString getModel();
    double getMileage();
    void display();

    virtual QString * getallValues();

};

// Car and motorbike classes
// Inherit from vehicle class
class Car : public Vehicle
{
private:
    double BasePrice;
    int SeaterNumber;
    int InsuranceCoverage;

public:
    void setvalues(int, QString, QString, double, double, int, int);
    double getBasePrice();
    int getSeaterNumber();
    // Total coverage by insurance.
    int getInsuranceCoverage();
    void display();
};

class Motorbike : public Vehicle
{
private:
    double BasePrice;
    // Total coverage by insurance.
    int InsuranceCoverage;

public:
    void setvalues(int, QString, QString, double, double, int);
    double getBasePrice();
    int getInsuranceCoverage();
    void display();
};

// The following classes are children of the Car/Motorbike Class.

// Car classes
class ElectricCar : virtual public Car
{
private:
    double PricePerCharge;
    // Battery life of the car in hours.
    int BatteryLife;

public:
    ElectricCar(int = 0, QString = NULL, QString = NULL, double = 0, double = 0, int = 0, int = 0, double = 0, int = 0);
    double getPricePerCharge();
    int getBatteryLife();
    virtual QString * getallValues();
};

class GasCar : virtual public Car
{
private:
    double kmPerLitre;

public:
    GasCar(int = 0, QString = NULL, QString = NULL, double = 0, double = 0, int = 0, int = 0, double = 0);
    double getkmPerLitre();
    virtual QString * getallValues();
};

// Hybrid of electric and gas car
class HybridCar : public GasCar, public ElectricCar
{
public:
    HybridCar(int = 0, QString = NULL, QString = NULL, double = 0, double = 0, int = 0, int = 0, double = 0, int = 0, double = 0);
    virtual QString * getallValues();
};

// Motorbike classes
class ElectricMotorbike : virtual public Motorbike
{
private:
    double PricePerCharge;
    int BatteryLife;

public:
    ElectricMotorbike(int = 0, QString = NULL, QString = NULL, double = 0, double = 0, int = 0, double = 0, int = 0);
    double getPricePerCharge();
    int getBatteryLife();
    virtual QString * getallValues();
};

class GasMotorbike : virtual public Motorbike
{
private:
    double kmPerLitre;

public:
    GasMotorbike(int = 0, QString = NULL, QString = NULL, double = 0, double = 0, int = 0, double = 0);
    double getkmPerLitre();
    virtual QString * getallValues();
};

// Hybrid of electric and gas motorbike
class HybridMotorbike : public GasMotorbike, public ElectricMotorbike
{
public:
    HybridMotorbike(int = 0, QString = NULL, QString = NULL, double = 0, double = 0, int = 0, double = 0, int = 0, double = 0);
    virtual QString * getallValues();
};

#endif
