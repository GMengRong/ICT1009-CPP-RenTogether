#include "rentalform.h"
#include "ui_rentalform.h"

rentalform::rentalform(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::rentalform)
{
    ui->setupUi(this);

}

rentalform::~rentalform()
{
    delete ui;
}

