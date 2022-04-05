#ifndef SECDIALOG_H
#define SECDIALOG_H

#include <QDialog>
#include "jsonreader.h"
#include "rentalform.h"

namespace Ui {
class SecDialog;
}

QT_BEGIN_NAMESPACE
class QTableWidget;
class QDialogButtonBox;
class QAction;
QT_END_NAMESPACE

class SecDialog : public QDialog
{
    Q_OBJECT

public:
    explicit SecDialog(QWidget *parent = nullptr);
    ~SecDialog();

       jsonReader &getReader();
       void setReader(jsonReader &newReader);

       void VehicleTableDisplay();
       void TableWidgetDisplay();

//public slots:
//    void openDialog();

//private slots:
//    void on_rentBtn_clicked();

private:
    Ui::SecDialog *ui;

    QStringList vehicledetails;
    QTableWidget *rentTable;
//    QDialogButtonBox *rentbtn;
//    QAction *openAction;
    jsonReader reader;
};

#endif // SECDIALOG_H
