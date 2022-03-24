#ifndef SECDIALOG_H
#define SECDIALOG_H

#include <QDialog>

//#include <QtSql/QSqlDatabase>
//#include <QtSql/QSqlTableModel>

namespace Ui {
class SecDialog;
}

class SecDialog : public QDialog
{
    Q_OBJECT

public:
    explicit SecDialog(QWidget *parent = nullptr);
    ~SecDialog();
//    QSqlTableModel *model;
//    QSqlDatabase db;
//    bool createDB(QString dbname);
//    void setVehicalID(const QString VID);
//    void setBrand(const QString brand);
//    void setModel(const QString model);


private:
    Ui::SecDialog *ui;
};

#endif // SECDIALOG_H
