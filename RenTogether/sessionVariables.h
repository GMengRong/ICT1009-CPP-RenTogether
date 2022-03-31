#ifndef SESSIONVARIABLES_H
#define SESSIONVARIABLES_H

#include <QVector>
#include <QHash>
#include <objects/user.h>

QVector<QStringList> electricBike{{}, {}, {}};
QVector<QStringList> electricCar{{}, {}, {}};
QVector<QStringList> gasBike{{}, {}, {}};
QVector<QStringList> gasCar{{}, {}, {}};
QVector<QStringList> hybridBike{{}, {}, {}};
QVector<QStringList> hybridCar{{}, {}, {}};

//QHash<QString, User> electricBike;
//QHash<QString, User> electricCar;
//QHash<QString, User> gasBike;
//QHash<QString, User> gasCar;
//QHash<QString, User> hybridBike;
//QHash<QString, User> hybridCar;

QHash<QString, User> userHashMap;


#endif // SESSIONVARIABLES_H
