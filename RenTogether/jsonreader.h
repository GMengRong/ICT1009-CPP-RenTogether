#ifndef JSONREADER_H
#define JSONREADER_H

#include <QHash>
#include "RenTogether.h"

class jsonReader
{
    QVector<Vehicle*> vehicleList;
    QVector<Rental*> rentalList;
    int vehiclecounter = 0;

//    QHash<QString, Customer*> customerHashMap;
    QVector<Customer*> customerList;
    Customer* currentCustomer;

public:
    jsonReader();
    int initialiseLists();

    QVector<Vehicle*> getVehicleList();
    QVector<Rental*> getRentalList();
    void setRentalList(QVector<Rental*>);
    int getVehicleCounter();
    void setvehicleCounter(int);

    //    QHash<QString, Customer*> getCustomerHashMap();
    QVector<Customer*> getCustomerList();
    Customer* getCurrentCustomer();
    void setCurrentCustomer(Customer *);
};

#endif // JSONREADER_H
