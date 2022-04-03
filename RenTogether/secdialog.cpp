#include "secdialog.h"
#include "qheaderview.h"
#include "ui_secdialog.h"
#include "QTableWidget"
#include <QTableWidgetItem>
#include <QHeaderView>

SecDialog::SecDialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::SecDialog)
{
    ui->setupUi(this);
    TableWidgetDsiplay();
    RentsTableDisplay();
}

SecDialog::~SecDialog()
{
    delete ui;
}

// View Rents Table
void SecDialog::RentsTableDisplay(){

    QTableWidget *table2 = new QTableWidget(this->ui->viewRents);
    table2->setRowCount(6);
    table2->setColumnCount(1);
    table2->setColumnWidth(30, 30);

    QStringList vLabels;
    vLabels << "Brand:" << "Model:" << "Seater Number:" << "Battery Life:" << "Mileage:" << "Base Price:";
    table2->setVerticalHeaderLabels(vLabels);
    table2->setHorizontalHeaderLabels(vLabels);

    QTableWidgetItem *itemRents;
    itemRents = new QTableWidgetItem;

//    display vehicles
//    for( int i = 0; i < TeslaS.count(); ++i ){

//        itemRents = (qDebug() << eclist[x])->setText();
//        table2->setItem( 0, 0, itemRents );
//        itemRents = new QTableWidgetItem;

//    }

    itemRents->setText("Scorpio Electric");
    table2->setItem(0,0, itemRents);
    itemRents = new QTableWidgetItem;

    itemRents->setText("X1");
    table2->setItem(1,0, itemRents);
    itemRents = new QTableWidgetItem;

    itemRents->setText("");
    table2->setItem(2,0, itemRents);
    itemRents = new QTableWidgetItem;

    itemRents->setText("100");
    table2->setItem(3,0, itemRents);
    itemRents = new QTableWidgetItem;

    itemRents->setText("");
    table2->setItem(4,0, itemRents);
    itemRents = new QTableWidgetItem;

    itemRents->setText("40");
    table2->setItem(5,0, itemRents);
    itemRents = new QTableWidgetItem;

    //Table Properties
    table2->setShowGrid(false);
    table2->setGridStyle(Qt::DotLine);
    table2->setSortingEnabled(true);

    //Header Properties
    table2->verticalHeader()->setVisible(true);
    table2->horizontalHeader()->setVisible(false);
    table2->verticalHeader()->setDefaultSectionSize(10);

}

// View Rental Table Display
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


//void SecDialog::on_rentBtn_clicked()
//{

//}

