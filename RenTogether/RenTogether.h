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
    QString username;
    QString hash;

public:
    Customer(int = NULL, QString = NULL, QString = NULL, QString = NULL, QString = NULL, QString = NULL);
    int getCustomerID();
    QString getFirstName();
    QString getLastName();
    QString getEmail();
    QString getUsername();
    QString getHash();
    void printUser();
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
    // This function returns the string containing the class name of the object, allowing us to
    // identify the vehicle called.
    virtual QString getVehicleType();

    // This function returns a qString and qString key-pair map of all the values
    // within a vehicle object. This is important for printing the details of vehicles
    // in our GUI.
    virtual QMap<QString,QString> getallValues();

    // This function gets the base price of the child object, car or motorbike.
    virtual double getBasePrice();
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
    virtual double getBasePrice();
    int getSeaterNumber();
    // Total coverage by insurance.
    int getInsuranceCoverage();
};

class Motorbike : public Vehicle
{
private:
    double BasePrice;
    // Total coverage by insurance.
    int InsuranceCoverage;

public:
    void setvalues(int, QString, QString, double, double, int);
    virtual double getBasePrice();
    int getInsuranceCoverage();
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
    virtual QString getVehicleType();
    virtual QMap<QString,QString> getallValues();
};

class GasCar : virtual public Car
{
private:
    double kmPerLitre;

public:
    GasCar(int = 0, QString = NULL, QString = NULL, double = 0, double = 0, int = 0, int = 0, double = 0);
    double getkmPerLitre();
    virtual QString getVehicleType();
    virtual QMap<QString,QString> getallValues();
};

// Hybrid of electric and gas car
class HybridCar : public GasCar, public ElectricCar
{
public:
    HybridCar(int = 0, QString = NULL, QString = NULL, double = 0, double = 0, int = 0, int = 0, double = 0, int = 0, double = 0);
    virtual QString getVehicleType();
    virtual QMap<QString,QString> getallValues();
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
    virtual QString getVehicleType();
    virtual QMap<QString,QString> getallValues();
};

class GasMotorbike : virtual public Motorbike
{
private:
    double kmPerLitre;

public:
    GasMotorbike(int = 0, QString = NULL, QString = NULL, double = 0, double = 0, int = 0, double = 0);
    double getkmPerLitre();
    virtual QString getVehicleType();
    virtual QMap<QString,QString> getallValues();
};

// Hybrid of electric and gas motorbike
class HybridMotorbike : public GasMotorbike, public ElectricMotorbike
{
public:
    HybridMotorbike(int = 0, QString = NULL, QString = NULL, double = 0, double = 0, int = 0, double = 0, int = 0, double = 0);
    virtual QString getVehicleType();
    virtual QMap<QString,QString> getallValues();
};

#endif
