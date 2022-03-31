#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QMessageBox>
#include <iostream>

#include "sessionVariables.h"
#include "objects/user.h"

using namespace std;

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
    QString password = ui->passwdInput->text();

    //implement hash function later
    if(userHashMap[username].getPassword() == password) {
        QMessageBox::information(this, "Login", "Welcome!");
        hide();
        secdialog = new SecDialog(this);
        secdialog->show();
    }
    else {
        QMessageBox::warning(this,"Login", "Incorrect login details");
    }
}

