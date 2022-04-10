#include "secdialog.h"
#include "qheaderview.h"
#include "ui_secdialog.h"
#include "QTableWidget"
#include <QTableWidgetItem>
#include <QHeaderView>
#include <iostream>

#include "jsonreader.h"
#include "RenTogether.h"
#include "rentalform.h"
#include <QVector>
#include <QtWidgets>

using namespace std;

const QString ERROR_MSG ="ERROR! unable to open rental form.";

SecDialog::SecDialog(QWidget *parent, jsonReader* currentreader) : QDialog(parent) ,  ui(new Ui::SecDialog)
{
    setReader(currentreader);
    ui->setupUi(this);

    //Functions to set up both rent and vehicle tables
    RentTableDisplay();
    VehicleTableDisplay();
}

SecDialog::~SecDialog()
{
    delete ui;
}

void SecDialog::setReader(jsonReader *newReader){
    this->reader = *newReader;
};

// Getters and setters for current vehicle
Vehicle* SecDialog::getSelectedVehicle() {
    return this->selectedVehicle;
};

void SecDialog::setSelectedVehicle(Vehicle* selectVehicle){
    this->selectedVehicle = selectVehicle;
};

// Function to create Vehicles Table
void SecDialog::VehicleTableDisplay(){
    static int vehicleNo;
    vehicleNo = reader.getVehicleCounter();

    QVector<Vehicle*> vehiclelist = reader.getVehicleList();
    // Create vehicle table in secdialog ui under viewRents tab
    vehicleTable = new QTableWidget(this->ui->viewRents);
    vehicleTable->setRowCount(vehicleNo);
    vehicleTable->setColumnCount(7);
    vehicleTable->setMinimumWidth(2000);
    vehicleTable->setColumnWidth(0, 100);
    vehicleTable->setMinimumHeight(5000);

    // Vehicle table headers
    QStringList hLabels;
    hLabels <<"Brand"<<"Model"<<"Base Price"<<"Mileage"<<"Seater Number"<<"Battery Life" << "Button";
    vehicleTable->setHorizontalHeaderLabels(hLabels);
    vehicleTable->setSelectionMode(QAbstractItemView::SingleSelection);
    vehicleTable->setSelectionBehavior(QAbstractItemView::SelectRows);
    vehicleTable->setEditTriggers(QAbstractItemView::NoEditTriggers);

    // To display data for all vehicles
    for(int row = 0; row < vehicleNo ; ++row){

        // Retreive vehicle values
        QMap<QString,QString> strmap = vehiclelist[row]->getallValues();

        QTableWidgetItem *brand = new QTableWidgetItem(strmap.value("Brand"));
        vehicleTable->setItem(row, 0, brand);

        QTableWidgetItem *model = new QTableWidgetItem(strmap.value("Model"));
        vehicleTable->setItem(row, 1, model);

        QTableWidgetItem *basePrice = new QTableWidgetItem("SGD$" + strmap.value("BasePrice"));
        vehicleTable->setItem(row, 2, basePrice);

        QTableWidgetItem *mileage = new QTableWidgetItem(strmap.value("Mileage") + " km");
        vehicleTable->setItem(row, 3, mileage);

        //Electric Car
        if (checkDerived<ElectricCar*>(vehiclelist[row]) or checkDerived<HybridCar*>(vehiclelist[row]))
        {
            QTableWidgetItem *seaterNo = new QTableWidgetItem(strmap.value("SeaterNumber"));
            vehicleTable->setItem(row, 4, seaterNo);

            QTableWidgetItem *battLife = new QTableWidgetItem(strmap.value("BatteryLife")+" hours");
            vehicleTable->setItem(row, 5, battLife);
        }
        //Gas Car
        else if(checkDerived<GasCar*>(vehiclelist[row])){

            QTableWidgetItem *seaterNo = new QTableWidgetItem(strmap.value("SeaterNumber"));
            vehicleTable->setItem(row, 4, seaterNo);

            // No available data for battery life, print "-"
            QTableWidgetItem *nullbattLife = new QTableWidgetItem("-");
            vehicleTable->setItem(row, 5, nullbattLife);
        }
        // Hybrid Bike and Electric Bike
        else if (checkDerived<HybridMotorbike*>(vehiclelist[row]) or checkDerived<ElectricMotorbike*>(vehiclelist[row]))
        {
            // No available data for seater number, print "-"
            QTableWidgetItem *nullseaterNo = new QTableWidgetItem("-");
            vehicleTable->setItem(row, 4, nullseaterNo);

            QTableWidgetItem *battLife = new QTableWidgetItem(strmap.value("BatteryLife")+" hours");
            vehicleTable->setItem(row, 5, battLife);
        }
        // Gas Bike
        else if (checkDerived<GasMotorbike*>(vehiclelist[row]))
        {
            // No available data for seater number, print "-"
            QTableWidgetItem *nullseaterNo = new QTableWidgetItem("-");
            vehicleTable->setItem(row, 4, nullseaterNo);

            // No available data for battery life, print "-"
            QTableWidgetItem *nullbattLife = new QTableWidgetItem("-");
            vehicleTable->setItem(row, 5, nullbattLife);
        }

        // Display rent button at last column of table
        rentbtn = new QPushButton("Rent");
        vehicleTable->setCellWidget(row, 6, rentbtn);
        Vehicle* selectedveh = vehiclelist[row];
        jsonReader* currentreader = &reader;

        // To connect the rent button with the "openform" function, and send
        // the current vehicle and the reader data as an argument to the function.
        connect(rentbtn, &QAbstractButton::clicked, this, [=]{openform(selectedveh, currentreader);});
    }
}

// Function to obtain the derived class of the upcasted object
template <class T>
int SecDialog::checkDerived(Vehicle* parent) {
    T child = dynamic_cast<T>(parent);
    if (child != nullptr) {
        return 1;
    }else {
        return 0;
    }
}

// Function to open rental form
void SecDialog::openform(Vehicle* selectedvehicle, jsonReader* currentreader)
{
    setSelectedVehicle(selectedvehicle);

        // try to create rental form
    try{

        // To construct the rental form object.
        class rentalform newform(tr("Vehicle Details"), this, selectedvehicle, currentreader);

        if (newform.exec() == QDialog::Accepted) {

            RentTableDisplay();

        }else{// if unable to open, throw error message
            throw(ERROR_MSG);
        }
    }
    catch(QString ERROR_MSG){
        QMessageBox::warning(this,"Vehicle Details", ERROR_MSG);
    }
}


// View Rental Table Display
void SecDialog::RentTableDisplay(){

    // Create rent table in secdialog ui under viewRental tab
    rentsTable= new QTableWidget(this->ui->viewRental);
    rentsTable->setColumnCount(5);
    rentsTable->setColumnWidth(0, 50);
    rentsTable->setMinimumHeight(5000);

    //Rent table headers
    QStringList hLabels;
    hLabels <<"Car Brand"<<"Car Model"<<"Start Date"<<"End Date"<<"Price";
    rentsTable->setHorizontalHeaderLabels(hLabels);
    rentsTable->setSelectionMode(QAbstractItemView::SingleSelection);
    rentsTable->setSelectionBehavior(QAbstractItemView::SelectRows);
    rentsTable->setEditTriggers(QAbstractItemView::NoEditTriggers);
    rentsTable->setMinimumWidth(2000);

    //insert data
    QTableWidgetItem *item;
    rentsTable->setRowCount(5);
    QVector<Rental *> rentallist = reader.getRentalList();
    QVector<Vehicle*> vehiclelist = reader.getVehicleList();
    int customerId = reader.getCurrentCustomer()->getCustomerID();
    QString brand;
    QString model;
    int count = 0;
    rentsTable->setRowCount(rentallist.size());
    for(int i = 0 ; i < rentallist.size() ; i ++){
    if(customerId == rentallist[i]->getCustomerID()){
        for(int j = 0 ; j < vehiclelist.size();j++){
            if(rentallist[i]->getVehicleID() == vehiclelist[j]->getVehicleID()){
                brand = vehiclelist[j]->getBrand();
                model = vehiclelist[j]->getModel();
                break;
            }
        }
        item = new QTableWidgetItem;
        item->setText(brand);
        rentsTable->setItem(count,0, item);

        item = new QTableWidgetItem;
        item->setText(model);
        rentsTable->setItem(count,1, item);

        item = new QTableWidgetItem;
        item->setText(rentallist[i]->getStartDate());
        rentsTable->setItem(count,2, item);

        item = new QTableWidgetItem;
        item->setText(rentallist[i]->getEndDate());
        rentsTable->setItem(count,3, item);

        item = new QTableWidgetItem;
        item->setText("SGD$"+QString::number(rentallist[i]->getprice()));
        rentsTable->setItem(count,4, item);
        count++;
    }

    }
    rentsTable->setRowCount(count);

    //Table Properties
    rentsTable->setShowGrid(true);
    rentsTable->setGridStyle(Qt::DotLine);
    rentsTable->setSortingEnabled(true);
    rentsTable->setCornerButtonEnabled(true);

    //Header Properties
    rentsTable->horizontalHeader()->setVisible(true);
    rentsTable->horizontalHeader()->setDefaultSectionSize(100);

}
