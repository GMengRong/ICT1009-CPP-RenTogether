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

SecDialog::SecDialog(QWidget *parent, jsonReader* reader) :
    QDialog(parent),
    ui(new Ui::SecDialog)
{
    ui->setupUi(this);
    TableWidgetDisplay();
//    VehicleTableDisplay();

    //     layout of rent table
//    QGridLayout *mainLayout = new QGridLayout;
//    mainLayout->SetFixedSize(300,450);

 //   mainLayout->addWidget(rentTable, 5, 5, 2, 1);
 //   setLayout(mainLayout);


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

    rentTable = new QTableWidget(16, 7); //create table with 16 rows and 6 columns

    // header
    QTableWidgetItem *brand = new QTableWidgetItem(vehicledetails[0]);
    rentTable->setItem(0, 0, brand);

    QTableWidgetItem *model = new QTableWidgetItem(vehicledetails[1]);
    rentTable->setItem(0, 1, model);

    QTableWidgetItem *basePrice = new QTableWidgetItem(vehicledetails[2]);
    rentTable->setItem(0, 2, basePrice);

    QTableWidgetItem *mileage = new QTableWidgetItem(vehicledetails[3]);
    rentTable->setItem(0, 3, mileage);

    QTableWidgetItem *seaterNo = new QTableWidgetItem(vehicledetails[4]);
    rentTable->setItem(0, 4, seaterNo);

    QTableWidgetItem *battLife = new QTableWidgetItem(vehicledetails[5]);
    rentTable->setItem(0, 5, battLife);

    // display data
    for(int row = 1; row < vehicleNo ; ++row){

        QMap<QString,QString> strmap = test[row-1]->getallValues();

        QTableWidgetItem *brand = new QTableWidgetItem(strmap.value("Brand"));
        rentTable->setItem(row, 0, brand);

        QTableWidgetItem *model = new QTableWidgetItem(strmap.value("Model"));
        rentTable->setItem(row, 1, model);

        QTableWidgetItem *basePrice = new QTableWidgetItem("$" + strmap.value("BasePrice"));
        rentTable->setItem(row, 2, basePrice);

        QTableWidgetItem *mileage = new QTableWidgetItem(strmap.value("Mileage"));
        rentTable->setItem(row, 3, mileage);

        // Electric Car and Hybrid Car
        if (test[row-1]->getVehicleType() == "ElectricCar" or test[row-1]->getVehicleType() == "HybridCar")
        {
            QTableWidgetItem *seaterNo = new QTableWidgetItem(strmap.value("SeaterNumber"));
            rentTable->setItem(row, 4, seaterNo);

            QTableWidgetItem *battLife = new QTableWidgetItem(strmap.value("BatteryLife"));
            rentTable->setItem(row, 5, battLife);

        }
        // Gas Car
        else if(test[row-1]->getVehicleType() == "GasCar"){

            QTableWidgetItem *seaterNo = new QTableWidgetItem(strmap.value("SeaterNumber"));
            rentTable->setItem(row, 4, seaterNo);

            QTableWidgetItem *nullbattLife = new QTableWidgetItem("-");
            rentTable->setItem(row, 5, nullbattLife);
        }
        // Hybrid Bike and Electric Bike
        else if (test[row-1]->getVehicleType() == "HybridMotorbike" or test[row-1]->getVehicleType() == "ElectricMotorbike")
        {
            QTableWidgetItem *nullseaterNo = new QTableWidgetItem("-");
            rentTable->setItem(row, 4, nullseaterNo);

            QTableWidgetItem *battLife = new QTableWidgetItem(strmap.value("BatteryLife"));
            rentTable->setItem(row, 5, battLife);
        }
        // Gas Bike
        else
        {
            QTableWidgetItem *nullseaterNo = new QTableWidgetItem("-");
            rentTable->setItem(row, 4, nullseaterNo);

            QTableWidgetItem *nullbattLife = new QTableWidgetItem("-");
            rentTable->setItem(row, 5, nullbattLife);
        }

        rentbtn = new QPushButton("Rent");
        rentTable->setCellWidget(row, 6, rentbtn);
        Vehicle* selectedveh = test[row-1];
        jsonReader* currentreader = &reader;

//        QSignalMapper* signalMapper = new QSignalMapper (this);
//        connect(rentbtn, SIGNAL(clicked()), signalMapper, SLOT(map()));
//        signalMapper -> setMapping(rentbtn, 1);
//        connect (signalMapper, SIGNAL(mapped(Vehicle*)), signalMapper, SLOT(openform(Vehicle*))) ;
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
void SecDialog::TableWidgetDisplay(){
     QTableWidget *table = new QTableWidget(this->ui->viewRental);
     table->setColumnCount(5);
     table->setColumnWidth(0, 50);

     QStringList hLabels;
     hLabels <<"Car Model"<<"Customer ID"<<"Start Date"<<"End Date"<<"Price";
     table->setHorizontalHeaderLabels(hLabels);
     table->setSelectionMode(QAbstractItemView::SingleSelection);
     table->setSelectionBehavior(QAbstractItemView::SelectRows);
     table->setEditTriggers(QAbstractItemView::NoEditTriggers);
     table->setMinimumWidth(20);

     //insert data
     QTableWidgetItem *item;
     table->setRowCount(5);
     QVector<Rental *> list_ = reader.getRentalList();
     QVector<Vehicle*> test_ = reader.getVehicleList();
     //int customerId =  reader.getCurrentCustomer()->getCustomerID();
     int customerId = 3;
     int count = 0;
     table->setRowCount(list_.size());
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
         table->setItem(count,0, item);

         item = new QTableWidgetItem;
         item->setText(QString::number(list_[i]->getCustomerID()));
          table->setItem(count,1, item);

         item = new QTableWidgetItem;
         item->setText(list_[i]->getStartDate());
         table->setItem(count,2, item);

         item = new QTableWidgetItem;
         item->setText(list_[i]->getEndDate());
         table->setItem(count,3, item);

         item = new QTableWidgetItem;
         item->setText(QString::number(list_[i]->getprice()));
         table->setItem(count,4, item);
         qDebug() <<  list_[i]->getprice();
          count++;
     }

     }
     table->setRowCount(count);

 //    //Table Properties
     table->setShowGrid(true);
     table->setGridStyle(Qt::DotLine);
     table->setSortingEnabled(true);
     table->setCornerButtonEnabled(true);

     //Header Properties
     table->horizontalHeader()->setVisible(true);
     table->horizontalHeader()->setDefaultSectionSize(100);

 }
