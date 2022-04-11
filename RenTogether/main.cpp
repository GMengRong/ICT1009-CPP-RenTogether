#include "mainwindow.h"
#include <QApplication>
#include <QObject>
#include <QDebug>

#include <iostream>

#include "jsonreader.h"
#include "RenTogether.h"

int main(int argc, char *argv[])
{

    QApplication a(argc, argv);

    // If error in the initialisation, exit program
    jsonReader reader;
    if (reader.initialiseLists()) {
        return 0;
    }

    MainWindow w;
    w.setReader(reader);
    w.show();

    return a.exec();
}
