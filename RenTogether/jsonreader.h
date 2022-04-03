#ifndef JSONREADER_H
#define JSONREADER_H

#include <QHash>
#include "objects/user.h"
#include "RenTogether.h"

class jsonReader
{

    QHash<int, ElectricMotorbike> electricBike;
    QHash<int, ElectricCar> electricCar;
    QHash<int, GasMotorbike> gasBike;
    QHash<int, GasCar> gasCar;
    QHash<int, HybridMotorbike> hybridBike;
    QHash<int, HybridCar> hybridCar;
//    QVector<QStringList> electricCar{{}, {}, {}};
//    QVector<QStringList> gasBike{{}, {}, {}};
//    QVector<QStringList> gasCar{{}, {}, {}};
//    QVector<QStringList> hybridBike{{}, {}, {}};
//    QVector<QStringList> hybridCar{{}, {}, {}};
//    QVector<User> userList{};

    QHash<QString, User> userHashMap;

public:
    jsonReader();
    QHash<int, ElectricMotorbike> &getElectricBike();
    QHash<int, ElectricCar> &getElectricCar();
    QHash<int, GasMotorbike> &getGasBike();
    QHash<int, GasCar> &getGasCar();
    QHash<int, HybridMotorbike> &getHybridBike();
    QHash<int, HybridCar> &getHybridCar();
    QHash<QString, User> &getUserHashMap();

    QList<Vehicle> getAllHashmap();
};

#endif // JSONREADER_H
