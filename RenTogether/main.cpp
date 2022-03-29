#include "mainwindow.h"
#include "jsonReader.h"

#include <QApplication>
#include <iostream>



int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    MainWindow w;
    w.show();

    // call Jsonreader function in JsonReader.cpp
    jsonReader();

    return a.exec();
}
