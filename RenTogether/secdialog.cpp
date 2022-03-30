#include "secdialog.h"
#include "qheaderview.h"
#include "ui_secdialog.h"
#include "QTableWidget"
#include <QTableWidgetItem>

SecDialog::SecDialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::SecDialog)
{
    ui->setupUi(this);
    TableWidgetDsiplay();


    ui->Brand->setText("Scorpio Electric");
    ui->SeaterNumber->setText("");
    ui->Model->setText("X1");
    ui->BatteryLife->setText("100");
    ui->Mileage->setText("");
    ui->BasePrice->setText("40");

    ui->Brand->setText("Energica");
    ui->SeaterNumber->setText("");
    ui->Model->setText("EGO+");
    ui->BatteryLife->setText("100");
    ui->Mileage->setText("");
    ui->BasePrice->setText("45");

    ui->Brand->setText("Harley-Davidson");
    ui->SeaterNumber->setText("");
    ui->Model->setText("LiveWire");
    ui->BatteryLife->setText("100");
    ui->Mileage->setText("");
    ui->BasePrice->setText("60");
}

SecDialog::~SecDialog()
{
    delete ui;
}

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
