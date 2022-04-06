#ifndef SECDIALOG_H
#define SECDIALOG_H

#include <QDialog>
#include "jsonreader.h"
#include "rentalform.h"
class QVBoxLayout;

namespace Ui {
class SecDialog;
}

QT_BEGIN_NAMESPACE
class QTableWidget;
class QPushButton;
class QDialogButtonBox;
class QVBoxLayout;
QT_END_NAMESPACE

class SecDialog : public QDialog
{
    Q_OBJECT

public:
    SecDialog(QWidget*, jsonReader*);
    ~SecDialog();

    jsonReader &getReader();
    void setReader(jsonReader *newReader);
    void setSelectedVehicle(Vehicle*);
    Vehicle* getSelectedVehicle();
       void VehicleTableDisplay();
       void TableWidgetDisplay();



public slots:
    void openform(Vehicle*, jsonReader*);

private:
    Ui::SecDialog *ui;

    QStringList vehicledetails;
    QTableWidget *rentTable;
    QPushButton *rentbtn;
    jsonReader reader;
    Vehicle* selectedVehicle;
};

#endif // SECDIALOG_H
