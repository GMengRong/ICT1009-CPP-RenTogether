#ifndef JSONREADER_H
#define JSONREADER_H

#include <QHash>
#include "RenTogether.h"

class jsonReader
{
    QVector<Vehicle*> vehicleList;
    QVector<Rental*> rentalList;
    QHash<QString, Customer> customerHashMap;
    int vehiclecounter;

public:
    jsonReader();
    QVector<Vehicle*> getVehicleList();
    QVector<Rental*> getRentalList();
    int getVehicleCounter();
    QHash<QString, Customer> getCustomerHashMap();
};

#endif // JSONREADER_H
