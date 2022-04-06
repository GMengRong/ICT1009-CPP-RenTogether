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
    QString tmp = "test";
    QString test = QString::fromStdString(sha256(tmp.toLocal8Bit().constData()));
    qDebug() << test;
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_loginButton_clicked()
{
    QString username = ui->userInput->text();

    // convert password input to std::string to hash and then converts it back to QString
    QString hash = QString::fromStdString(sha256(ui->passwdInput->text().toLocal8Bit().constData()));

//    qDebug() << reader.getCustomerHashMap()[username]->getHash();

//    //implement hash function later
//    if(reader.getCustomerHashMap()[username]->getHash() == hash) {

//        reader.setCurrentCustomer(reader.getCustomerHashMap()[username]);
//        QMessageBox::information(this, "Login", "Welcome!");

//        hide();
//        secdialog = new SecDialog(this);
//        secdialog->show();
//    }
//    else {
//        QMessageBox::warning(this,"Login", "Incorrect login details");
//    }

    QVector<Customer*> custList = reader.getCustomerList();

    int userIndex = -1;
    for (int i = 0; i < custList.size(); i++) {
        if (custList[i]->getUsername() == username) {
            userIndex = i;
            break;
        }
    }

    if (userIndex != -1) {
        //implement hash function later
        if(custList[userIndex]->getHash() == hash) {

            reader.setCurrentCustomer(custList[userIndex]);
            QString fn = reader.getCurrentCustomer()->getFirstName();
            QString ln = reader.getCurrentCustomer()->getLastName();
            QMessageBox::information(this, "Login", "Welcome! " + fn + " " + ln);

            hide();
            secdialog = new SecDialog(this);
            secdialog->show();
        }
        else {
            QMessageBox::warning(this,"Login", "Incorrect Login Credentials");
        }
    }
    else {
        QMessageBox::warning(this,"Login", "No user found");
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

