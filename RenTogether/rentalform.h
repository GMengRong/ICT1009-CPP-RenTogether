#ifndef RENTALFORM_H
#define RENTALFORM_H
#include<secdialog.h>

#include <QDialog>
#include <QList>
#include <QPair>
#include <QDateEdit>
#include <QtWidgets>
#include <QDate>

QT_BEGIN_NAMESPACE
class QDialogButtonBox;
class QLabel;
class QTableWidget;
class QWidget;
class QGroupBox;
QT_END_NAMESPACE

class rentalform : public QDialog
{
    Q_OBJECT

public slots:
    void verify();

public:
    rentalform(const QString &title, QWidget *parent, Vehicle* selectedvehicle, jsonReader* reader);

private:
    void setupDetailsTable();
    void createDateLabels();
    void setcurrentvehicle(Vehicle*);
    Vehicle* getcurrentvehicle();
    //void setcurrentcustomer(Customer*);
    //Customer* getcurrentcustomer();
    void setcurrentreader(jsonReader*);
    jsonReader* getcurrentreader();

    Vehicle* currentvehicle;
    //Customer* currentcustomer;
    jsonReader* currentreader;
    QLabel *nameLabel;
    QTableWidget *itemsTable;
    QDialogButtonBox *buttonBox;
    QDateEdit *rentalStartDatePicker;
    QDate rentalStartDate;
    QDate rentalEndDate;
    QGroupBox *rentalDatesGroup;
    QSpinBox *rentalDurationSelect;
};

#endif // RENTALFORM_H
