#include "mainwindow.h"
#include <QApplication>
#include <QObject>
#include <QDebug>

#include <iostream>
#include "universal_func.h"
#include "RenTogether.h"

int main(int argc, char *argv[])
{
    // call Jsonreader function in JsonReader.cpp
    jsonReader();

    QApplication a(argc, argv);
    MainWindow w;
    w.show();


    ElectricCar TeslaS(1, "Tesla", "S", 46.2, 200.4, 5, 10000, 50.5, 100);
    QString * eclist = TeslaS.getallValues();
    for (int x = 0; x < 10; x++){
        qDebug() << eclist[x];
    }

    qDebug() << "\n";
    GasCar HyundaiBB(2, "Hyundai", "BB", 46.2, 269.4, 5, 12000, 20.3);
    QString * gclist = HyundaiBB.getallValues();
    for (int x = 0; x < 10; x++){
        qDebug() << gclist[x];
    }
    qDebug() << "\n";
    HybridCar Prius(3, "Toyota", "Prius Plus", 102.5, 210.9, 7, 21000, 50.5, 100, 30.0);
    QString * hclist = Prius.getallValues();
    for (int x = 0; x < 10; x++){
        qDebug() << hclist[x];
    }
    qDebug() << "\n";
    GasMotorbike GBike(4, "Bandai", "bbBIKE", 102.5, 560.9, 26000, 12.2);
    QString * gmlist = GBike.getallValues();
    for (int x = 0; x < 10; x++){
        qDebug() << gmlist[x];
    }
    qDebug() << "\n";
    ElectricMotorbike EBike(5, "SGYP", "YOUNG PUNK", 102.5, 250.9, 20000, 75, 120);
    QString * emlist = EBike.getallValues();
    for (int x = 0; x < 8; x++){
        qDebug() << emlist[x];
    }
    qDebug() << "\n";
    HybridMotorbike HBike(6, "Hyper", "frogbike", 102.5, 300.9, 5000, 50, 100, 30.4);
    QString * hmlist = HBike.getallValues();
    for (int x = 0; x < 10; x++){
        qDebug() << hmlist[x];
    }
    qDebug() << "\n";

    Customer Customer1(1, "Wesley", "Chiau", "wesleychiau@gmail.com");
    qDebug() << Customer1.getCustomerID() << Customer1.getEmail() << Customer1.getFirstName() << Customer1.getLastName();

    Rental Rental1(1, 1, 3, "30-2-2022", "2-3-2022", 4, TeslaS.getBasePrice()*4);
    qDebug() << Rental1.getCustomerID() << Rental1.getEndDate() << Rental1.getStartDate() << Rental1.getVehicleID() << Rental1.getprice() << Rental1.getrentalID();;

    return a.exec();
}
