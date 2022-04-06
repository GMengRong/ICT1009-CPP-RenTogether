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

SecDialog::SecDialog(QWidget *parent, jsonReader* reader) : QDialog(parent)
{
    QWidget *window = new QWidget;
    setReader(reader);

    //RentTableDisplay();
    VehicleTableDisplay();
    QGridLayout *mainLayout = new QGridLayout(window);
    mainLayout->addWidget(vehicleTable, 5, 5, 2, 1);
    //mainLayout->addWidget(rentsTable, 10, 10, 4, 2);
    setLayout(mainLayout);
    resize(1000,1000);
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

// View Rents Table
void SecDialog::VehicleTableDisplay(){

    static int vehicleNo;
    vehicleNo = reader.getVehicleCounter();

    vehicledetails << tr("Brand:") << tr("Model:") << tr("Base Price:") << tr("Mileage:") << tr("Seater Number:") << tr("Battery Life:") ;
    QVector<Vehicle*> test = reader.getVehicleList();

    vehicleTable = new QTableWidget(16, 7); //create table with 16 rows and 6 columns

    // header
    QTableWidgetItem *brand = new QTableWidgetItem(vehicledetails[0]);
    vehicleTable->setItem(0, 0, brand);

    QTableWidgetItem *model = new QTableWidgetItem(vehicledetails[1]);
    vehicleTable->setItem(0, 1, model);

    QTableWidgetItem *basePrice = new QTableWidgetItem(vehicledetails[2]);
    vehicleTable->setItem(0, 2, basePrice);

    QTableWidgetItem *mileage = new QTableWidgetItem(vehicledetails[3]);
    vehicleTable->setItem(0, 3, mileage);

    QTableWidgetItem *seaterNo = new QTableWidgetItem(vehicledetails[4]);
    vehicleTable->setItem(0, 4, seaterNo);

    QTableWidgetItem *battLife = new QTableWidgetItem(vehicledetails[5]);
    vehicleTable->setItem(0, 5, battLife);

    // display data
    for(int row = 1; row < vehicleNo ; ++row){

        QMap<QString,QString> strmap = test[row-1]->getallValues();

        QTableWidgetItem *brand = new QTableWidgetItem(strmap.value("Brand"));
        vehicleTable->setItem(row, 0, brand);

        QTableWidgetItem *model = new QTableWidgetItem(strmap.value("Model"));
        vehicleTable->setItem(row, 1, model);

        QTableWidgetItem *basePrice = new QTableWidgetItem("$" + strmap.value("BasePrice"));
        vehicleTable->setItem(row, 2, basePrice);

        QTableWidgetItem *mileage = new QTableWidgetItem(strmap.value("Mileage"));
        vehicleTable->setItem(row, 3, mileage);

        // Electric Car and Hybrid Car
        if (test[row-1]->getVehicleType() == "ElectricCar" or test[row-1]->getVehicleType() == "HybridCar")
        {
            QTableWidgetItem *seaterNo = new QTableWidgetItem(strmap.value("SeaterNumber"));
            vehicleTable->setItem(row, 4, seaterNo);

            QTableWidgetItem *battLife = new QTableWidgetItem(strmap.value("BatteryLife"));
            vehicleTable->setItem(row, 5, battLife);

        }
        // Gas Car
        else if(test[row-1]->getVehicleType() == "GasCar"){

            QTableWidgetItem *seaterNo = new QTableWidgetItem(strmap.value("SeaterNumber"));
            vehicleTable->setItem(row, 4, seaterNo);

            QTableWidgetItem *nullbattLife = new QTableWidgetItem("-");
            vehicleTable->setItem(row, 5, nullbattLife);
        }
        // Hybrid Bike and Electric Bike
        else if (test[row-1]->getVehicleType() == "HybridMotorbike" or test[row-1]->getVehicleType() == "ElectricMotorbike")
        {
            QTableWidgetItem *nullseaterNo = new QTableWidgetItem("-");
            vehicleTable->setItem(row, 4, nullseaterNo);

            QTableWidgetItem *battLife = new QTableWidgetItem(strmap.value("BatteryLife"));
            vehicleTable->setItem(row, 5, battLife);
        }
        // Gas Bike
        else
        {
            QTableWidgetItem *nullseaterNo = new QTableWidgetItem("-");
            vehicleTable->setItem(row, 4, nullseaterNo);

            QTableWidgetItem *nullbattLife = new QTableWidgetItem("-");
            vehicleTable->setItem(row, 5, nullbattLife);
        }

        rentbtn = new QPushButton("Rent");
        vehicleTable->setCellWidget(row, 6, rentbtn);
        Vehicle* selectedveh = test[row-1];
        jsonReader* currentreader = &reader;

        connect(rentbtn, &QAbstractButton::clicked, this, [=]{openform(selectedveh, currentreader);});
    }
}

void SecDialog::openform(Vehicle* selectedvehicle, jsonReader* currentreader)
{
    setSelectedVehicle(selectedvehicle);

    class rentalform newform(tr("Vehicle Details"), this, selectedvehicle, currentreader);

    if (newform.exec() == QDialog::Accepted) {
        // to construct rental object
    }

}


// View Rental Table Display (Jing Kai's)
void SecDialog::RentTableDisplay(){
     QTableWidget *rentstable = new QTableWidget();
     rentstable->setColumnCount(5);
     rentstable->setColumnWidth(0, 50);

     QStringList hLabels;
     hLabels <<"Car Model"<<"Customer ID"<<"Start Date"<<"End Date"<<"Price";
     rentstable->setHorizontalHeaderLabels(hLabels);
     rentstable->setSelectionMode(QAbstractItemView::SingleSelection);
     rentstable->setSelectionBehavior(QAbstractItemView::SelectRows);
     rentstable->setEditTriggers(QAbstractItemView::NoEditTriggers);
     rentstable->setMinimumWidth(20);

     //insert data
     QTableWidgetItem *item;
     rentstable->setRowCount(5);
     QVector<Rental *> list_ = reader.getRentalList();
     QVector<Vehicle*> test_ = reader.getVehicleList();
     int customerId =  reader.getCurrentCustomer()->getCustomerID();

     int count = 0;
     rentstable->setRowCount(list_.size());
     for(int i = 0 ; i < list_.size() ; i ++){
     if(customerId == list_[i]->getCustomerID()){
         QString brand = "";
         for(int j = 0 ; j < test_.size();j++){
             if(list_[i]->getVehicleID() == test_[j]->getVehicleID()){
                 brand = test_[j]->getBrand();
                 break;
             }
         }
         item = new QTableWidgetItem;
         item->setText(brand);
         rentstable->setItem(count,0, item);

         item = new QTableWidgetItem;
         item->setText(QString::number(list_[i]->getCustomerID()));
         rentstable->setItem(count,1, item);

         item = new QTableWidgetItem;
         item->setText(list_[i]->getStartDate());
         rentstable->setItem(count,2, item);

         item = new QTableWidgetItem;
         item->setText(list_[i]->getEndDate());
         rentstable->setItem(count,3, item);

         item = new QTableWidgetItem;
         item->setText(QString::number(list_[i]->getprice()));
         rentstable->setItem(count,4, item);
         count++;
     }

     }
     rentstable->setRowCount(count);

     //Table Properties
     rentstable->setShowGrid(true);
     rentstable->setGridStyle(Qt::DotLine);
     rentstable->setSortingEnabled(true);
     rentstable->setCornerButtonEnabled(true);

     //Header Properties
     rentstable->horizontalHeader()->setVisible(true);
     rentstable->horizontalHeader()->setDefaultSectionSize(100);

 }
