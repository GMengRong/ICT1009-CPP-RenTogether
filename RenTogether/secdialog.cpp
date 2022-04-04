#include "secdialog.h"
#include "qheaderview.h"
#include "ui_secdialog.h"
#include "QTableWidget"
#include <QTableWidgetItem>
#include <QHeaderView>
#include <iostream>

#include "jsonreader.h"
#include <QVector>

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
    setLayout(mainLayout);
}

SecDialog::~SecDialog()
{
    delete ui;
}

// View Rents Table
void SecDialog::RentsTableDisplay(){

//    static int vehicleNo;
//        vehicleNo = reader.getVehicleCounter();

        vehicledetails << tr("Brand:") << tr("Model:")<< tr("Mileage:")<< tr("Base Price:");
        QVector<Vehicle*> test = reader.getVehicleList();
        rentTable = new QTableWidget(16, 4); //create table with 16 rows and 6 columns

        QTableWidgetItem *brand = new QTableWidgetItem(vehicledetails[0]);
        rentTable->setItem(0, 0, brand);

        QTableWidgetItem *model = new QTableWidgetItem(vehicledetails[1]);
        rentTable->setItem(0, 1, model);

        QTableWidgetItem *mileage = new QTableWidgetItem(vehicledetails[2]);
        rentTable->setItem(0, 2, mileage);

        QTableWidgetItem *basePrice = new QTableWidgetItem(vehicledetails[3]);
        rentTable->setItem(0, 3, basePrice);

            for(int row = 1; row < 17 ; ++row)
            {
                QString * strList = test[row-1]->getallValues();

                QTableWidgetItem *brand = new QTableWidgetItem(strList[0]);
                rentTable->setItem(row, 0, brand);

                QTableWidgetItem *model = new QTableWidgetItem(strList[1]);
                rentTable->setItem(row, 1, model);

                QTableWidgetItem *mileage = new QTableWidgetItem(strList[2]);
                rentTable->setItem(row, 2, mileage);

                QTableWidgetItem *basePrice = new QTableWidgetItem(strList[3]);
                rentTable->setItem(row, 3, basePrice);

            }
}


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

