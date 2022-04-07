#include "rentalform.h"
#include "RenTogether.h"
#include "secdialog.h"

rentalform::rentalform(const QString &title, QWidget *parent, Vehicle* selectedvehicle, jsonReader* reader) : QDialog(parent)
{
    nameLabel = new QLabel(tr("Vehicle Details:"));

    // To set the pointer values for the current vehicle and to obtain the returned user.
    setcurrentvehicle(selectedvehicle);
    setcurrentreader(reader);

    // Functions to set up the rental form
    setupDetailsTable();
    createDateLabels();

    // To set up the "ok" and "cancel" buttons
    buttonBox = new QDialogButtonBox(QDialogButtonBox::Ok | QDialogButtonBox::Cancel);

    connect(buttonBox, &QDialogButtonBox::accepted, this, &rentalform::verify);
    connect(buttonBox, &QDialogButtonBox::rejected, this, &rentalform::reject);

    QGridLayout *mainLayout = new QGridLayout;
    mainLayout->addWidget(nameLabel, 0, 0);
    mainLayout->addWidget(itemsTable, 0, 2, 2, 1);
    mainLayout->addWidget(rentalDatesGroup);
    mainLayout->addWidget(buttonBox, 3, 0, 1, 3);
    setLayout(mainLayout);

    setWindowTitle(title);
}

void rentalform::setupDetailsTable()
{
    Vehicle* selectedvehicle = this->getcurrentvehicle();
    QMap<QString,QString> vehicledetails = selectedvehicle->getallValues();
    itemsTable = new QTableWidget(vehicledetails.count(), 2);

    QTableWidgetItem *vehicletypelabel = new QTableWidgetItem("Vehicle Type:");
    QTableWidgetItem *vehicletype = new QTableWidgetItem(selectedvehicle->getVehicleType());
    itemsTable->setItem(0, 0, vehicletypelabel);
    itemsTable->setItem(0, 1, vehicletype);

    int row = 1;
    for(QMap<QString,QString>::iterator it = vehicledetails.begin(); it != vehicledetails.end(); ++it) {
        QTableWidgetItem *name = new QTableWidgetItem(it.key());
        itemsTable->setItem(row, 0, name);
        QTableWidgetItem *quantity = new QTableWidgetItem(it.value());
        itemsTable->setItem(row, 1, quantity);
        row++;
    }
}

void rentalform::createDateLabels()
{
    rentalDatesGroup = new QGroupBox(tr("Date and time spin boxes"));

    QLabel *dateLabel = new QLabel;
    rentalStartDatePicker = new QDateEdit(QDate::currentDate());
    rentalStartDatePicker->setDateRange(QDate::currentDate(), QDate::currentDate().addYears(1));
    dateLabel->setText(tr("Select date"));

    QLabel *integerLabel = new QLabel(tr("Enter the number of days for rental"));
    rentalDurationSelect = new QSpinBox;
    rentalDurationSelect->setSingleStep(1);
    rentalDurationSelect->setValue(1);
    rentalDurationSelect->setRange(1, 365);

    QVBoxLayout *editsLayout = new QVBoxLayout;
    editsLayout->addWidget(dateLabel);
    editsLayout->addWidget(rentalStartDatePicker);
    editsLayout->addWidget(integerLabel);
    editsLayout->addWidget(rentalDurationSelect);
    rentalDatesGroup->setLayout(editsLayout);
}

void rentalform::verify()
{
    rentalStartDate = rentalStartDatePicker->date();
    int duration = rentalDurationSelect->value();
    rentalEndDate = rentalStartDate.addDays(duration);

    QString startdate = rentalStartDate.toString("dd/MM/yyyy");
    QString enddate = rentalEndDate.toString("dd/MM/yyyy");

    if (!startdate.isEmpty() and !enddate.isEmpty() and duration>0) {
        accept();

        Vehicle * currentvehicle = getcurrentvehicle();
        int vehicleid = currentvehicle->getVehicleID();
        jsonReader * currentreader = getcurrentreader();

        QVector<Rental*> rentallist = currentreader->getRentalList();
        int customerid = currentreader->getCurrentCustomer()->getCustomerID();
        int newrentalid = rentallist.last()->getrentalID()+1;
        int price = duration * currentvehicle->getBasePrice();

        rentallist.push_back(new Rental(newrentalid, customerid, vehicleid, startdate, enddate, duration, price));
        currentreader->setRentalList(rentallist);
        return;
    }

    QMessageBox::StandardButton answer;
    answer = QMessageBox::warning(this, tr("Invalid Form"),
        tr("An error has occured. Try again?"),
        QMessageBox::Yes | QMessageBox::No);

    if (answer == QMessageBox::No)
        reject();
}

void rentalform::setcurrentvehicle(Vehicle* currentveh){
    this->currentvehicle = currentveh;
};

Vehicle* rentalform::getcurrentvehicle(){
    return this->currentvehicle;
};

void rentalform::setcurrentreader(jsonReader* reader){
    this->currentreader = reader;
};
jsonReader* rentalform::getcurrentreader(){
    return this->currentreader;
};
