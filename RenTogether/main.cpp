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

    return a.exec();
}
