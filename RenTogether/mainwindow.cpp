#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QMessageBox>
#include <iostream>

#include "jsonreader.h"
#include "RenTogether.h"
#include "objects/user.h"
#include "sha256.h" // hash function

#include <QVector>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);

}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_loginButton_clicked()
{
    QString username = ui->userInput->text();

    // convert password input to std::string to hash and then converts it back to QString
    QString password = QString::fromStdString(sha256(ui->passwdInput->text().toLocal8Bit().constData()));

    //implement hash function later
    if(reader.getCustomerHashMap()[username].getPassword() == password) {
        QMessageBox::information(this, "Login", "Welcome!");

        QVector<Vehicle*> test = reader.getVehicleList();

//        QString * variables;
        for (int i=0; i<6; i++){
            QString * list = test[i]->getallValues();
            for (int x=0; x<10; x++){
                qDebug() << list[x];
            }
        }

        hide();
        secdialog = new SecDialog(this);
        secdialog->show();
    }
    else {
        QMessageBox::warning(this,"Login", "Incorrect login details");
    }
}

jsonReader &MainWindow::getReader()
{
    return reader;
}

void MainWindow::setReader(jsonReader &newReader)
{
    reader = newReader;
}

