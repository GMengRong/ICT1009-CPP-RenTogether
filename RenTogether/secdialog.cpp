#include "secdialog.h"
#include "qheaderview.h"
#include "ui_secdialog.h"
#include "QTableWidget"
#include <QTableWidgetItem>
#include <QHeaderView>
#include <iostream>

#include "jsonreader.h"
#include "RenTogether.h"
#include <QVector>
#include <QtWidgets>

using namespace std;

SecDialog::SecDialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::SecDialog)
{
    ui->setupUi(this);
        TableWidgetDsiplay();
    RentsTableDisplay();

    //     layout of rent table
    QGridLayout *mainLayout = new QGridLayout;
    mainLayout->addWidget(rentTable, 0, 2, 2, 1);
//    mainLayout->addWidget(rentbtn, 3, 7, 1, 2);
    setLayout(mainLayout);

//    rentbtn = new QDialogButtonBox(QDialogButtonBox::Ok);
//    connect(rentbtn, &QDialogButtonBox::accepted, this);
}

SecDialog::~SecDialog()
{
    delete ui;
}

// View Rents Table
void SecDialog::RentsTableDisplay(){

    static int vehicleNo;
    vehicleNo = reader.getVehicleCounter();

    vehicledetails << tr("Brand:") << tr("Model:") << tr("Base Price:") << tr("Mileage:") << tr("Seater Number:") << tr("Battery Life:") ;
    QVector<Vehicle*> test = reader.getVehicleList();

    rentTable = new QTableWidget(16, 6); //create table with 16 rows and 6 columns

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

        if (test[row-1]->getVehicleType() == "ElectricCar" or test[row]->getVehicleType() == "HybridCar")
        {
            QTableWidgetItem *seaterNo = new QTableWidgetItem(strmap.value("SeaterNumber"));
            rentTable->setItem(row, 4, seaterNo);

            QTableWidgetItem *battLife = new QTableWidgetItem(strmap.value("BatteryLife"));
            rentTable->setItem(row, 5, battLife);
        }
        else if(test[row]->getVehicleType() == "GasCar"){

            QTableWidgetItem *seaterNo = new QTableWidgetItem(strmap.value("SeaterNumber"));
            rentTable->setItem(row, 4, seaterNo);

            QTableWidgetItem *nullbattLife = new QTableWidgetItem("-");
            rentTable->setItem(row, 5, nullbattLife);

        }
        else
        {
            QTableWidgetItem *nullseaterNo = new QTableWidgetItem("-");
            rentTable->setItem(row, 4, nullseaterNo);

            QTableWidgetItem *nullbattLife = new QTableWidgetItem("-");
            rentTable->setItem(row, 5, nullbattLife);
        }


    }


//    connect(openAction, this, &SecDialog::openDialog);
}

//void SecDialog::openDialog()
//{

//}

// View Rental Table Display (Jing Kai's)
void SecDialog::TableWidgetDsiplay(){
    QTableWidget *table = new QTableWidget(this->ui->viewRental);
    table->setRowCount(5);
    table->setColumnCount(5);
    table->setColumnWidth(0, 50);

    QStringList hLabels;
    hLabels <<"Rental ID"<<"Customer ID"<<"Start Date"<<"End Date"<<"Price";
    table->setHorizontalHeaderLabels(hLabels);
    table->setSelectionMode(QAbstractItemView::SingleSelection);
    table->setSelectionBehavior(QAbstractItemView::SelectRows);
    table->setEditTriggers(QAbstractItemView::NoEditTriggers);
    table->setMinimumWidth(2000);

    //insert data
    QTableWidgetItem *item;
    item = new QTableWidgetItem;

    item->setText("Scorpio Electric");
    table->setItem(0,0, item);
    item = new QTableWidgetItem;
    item->setText("Customer 1");
    table->setItem(0,1, item);
    item = new QTableWidgetItem;
    item->setText("1-1-2022");
    table->setItem(0,2, item);
    item = new QTableWidgetItem;
    item->setText("2-2-2022");
    table->setItem(0,3, item);
    item = new QTableWidgetItem;
    item->setText("200");
    table->setItem(0,4, item);

    //Table Properties
    table->setShowGrid(true);
    table->setGridStyle(Qt::DotLine);
    table->setSortingEnabled(true);
    table->setCornerButtonEnabled(true);

    //Header Properties
    table->horizontalHeader()->setVisible(true);
    table->horizontalHeader()->setDefaultSectionSize(100);

}







