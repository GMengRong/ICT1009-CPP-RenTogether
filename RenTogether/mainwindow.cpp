#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QMessageBox>

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

    if(username ==  "test" && password == "test") {
        QMessageBox::information(this, "Login", "Welcome!");
        hide();
        secdialog = new SecDialog(this);
        secdialog->show();
    }
    else {
        QMessageBox::warning(this,"Login", "Incorrect login details");
    }
}

