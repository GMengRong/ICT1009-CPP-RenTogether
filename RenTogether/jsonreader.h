#ifndef JSONREADER_H
#define JSONREADER_H

#include <QHash>
#include "objects/user.h"
#include "RenTogether.h"

class jsonReader
{
    QVector<Vehicle*> vehicleList;
    QVector<Rental*> rentalList;
    QHash<QString, User> userHashMap;
    int vehiclecounter;

public:
    jsonReader();
    QVector<Vehicle*> getVehicleList();
    QVector<Rental*> getRentalList();
    int getVehicleCounter();
    QHash<QString, User> &getUserHashMap();
};

#endif // JSONREADER_H
