#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include "secdialog.h"

#include <QHash>
#include "objects/user.h"
#include "jsonreader.h"


QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT


public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

    jsonReader &getReader();
    void setReader(jsonReader &newReader);


private slots:
    void on_loginButton_clicked();

private:
    Ui::MainWindow *ui;
    SecDialog *secdialog;

    jsonReader reader;
};
#endif // MAINWINDOW_H
