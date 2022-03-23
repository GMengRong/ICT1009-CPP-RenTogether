#include "rentogether.h"
#include "ui_rentogether.h"

#include <QtCore>
#include <QtGui>
#include <QMessageBox>


rentogether::rentogether(QWidget *parent)
    : QMainWindow(parent), ui(new Ui::rentogether)
{
    ui->setupUi(this);

    QFontDatabase::addApplicationFont(":/fonts/fonts/Facon.ttf");
    ui->title->setFont(QFont("Facon", 48, QFont::Normal, false));
}

rentogether::~rentogether()
{
    delete ui;
}


void rentogether::on_loginButton_clicked()
{
    QMessageBox::information(this, "Title here", "Hello world");
}
