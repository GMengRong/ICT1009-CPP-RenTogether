#include "rentogether.h"

#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);

    //RenTogether class is a subclass of the QMainWindow
    rentogether w;
    w.show();   //From Qt.widgets class base class of QMainWindow
    return a.exec();
}
