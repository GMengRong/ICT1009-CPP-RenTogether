#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QMessageBox>
#include <iostream>
#include <QPixmap>
#include "jsonreader.h"
#include "RenTogether.h"
#include "sha256.h" // hash function

#include <QVector>

const QString USER_ERROR = "No user found";
const QString LOGIN_ERROR = "Incorrect Login Credentials";

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    // set echomode to mask password
    ui->passwdInput->setEchoMode(QLineEdit::Password);

    // set placeholders for username and password input box
    ui->userInput->setPlaceholderText("Enter Username");
    ui->passwdInput->setPlaceholderText("Enter Password");

    QPixmap pix("://pics/avatar.jpg");
    int w = ui->label_pic->width();
    int h = ui->label_pic->height();
    ui->label_pic->setPixmap(pix.scaled(w,h,Qt::KeepAspectRatio));


}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_loginButton_clicked()
{

    // try to get user inputs and validate
    try {
        QString username = ui->userInput->text();


        // convert password input to std::string to hash and then converts it back to QString
        QString hash = QString::fromStdString(sha256(ui->passwdInput->text().toLocal8Bit().constData()));
        QVector<Customer*> custList = reader.getCustomerList();
        int userIndex = -1;
        for (int i = 0; i < custList.size(); i++) {
            if (custList[i]->getUsername() == username) {
                userIndex = i;
                break;
            }
        }

        if (userIndex != -1) {

            if(custList[userIndex]->getHash() == hash) {

                reader.setCurrentCustomer(custList[userIndex]);
                QString name = reader.getCurrentCustomer()->getFirstName() + " " + reader.getCurrentCustomer()->getLastName();
                throw(name);
            }
            else {
                // if credential is invalid, throw 1
                throw(1);
            }
        }
        else {
            // if invalid user, throw 2
            throw(2);
        }

    }catch (QString name) { // catch the name and display welcome message and show rental list
        QMessageBox::information(this, "Login", "Welcome! " + name);
        hide();
        secdialog = new SecDialog(this, &reader);
        secdialog->show();
    }catch (int error) { // catch all int throws. If 1, display LOGIN_ERROR, if 2 display USER_ERROR
        if(error == 1){
            QMessageBox::warning(this,"Login", LOGIN_ERROR);
        }else{
            QMessageBox::warning(this,"Login", USER_ERROR);
        }
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

