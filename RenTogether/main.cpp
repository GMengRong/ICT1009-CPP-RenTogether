#include "mainwindow.h"
#include <QApplication>
#include <QObject>
#include <QDebug>

#include <iostream>

#include "jsonreader.h"
#include "objects/user.h"
#include "RenTogether.h"

int main(int argc, char *argv[])
{

    jsonReader reader;

    QApplication a(argc, argv);
    MainWindow w;
    w.setReader(reader);
    w.show();


//    ElectricCar TeslaS(1, "Tesla", "S", 46.2, 200.4, 5, 10000, 50.5, 100);
//    QString * eclist = TeslaS.getallValues();
//    for (int x = 0; x < 10; x++){
//        qDebug() << eclist[x];
//    }

    return a.exec();
}
