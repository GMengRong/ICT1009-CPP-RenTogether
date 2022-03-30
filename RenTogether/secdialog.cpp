#include "secdialog.h"
#include "ui_secdialog.h"

SecDialog::SecDialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::SecDialog)
{
    ui->setupUi(this);

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
