#ifndef RENTALFORM_H
#define RENTALFORM_H

#include <QDialog>

namespace Ui {
class rentalform;
}

class rentalform : public QDialog
{
    Q_OBJECT

public:
    explicit rentalform(QWidget *parent = nullptr);
    ~rentalform();

//    void FormDisplay();

private:
    Ui::rentalform *ui;

};

#endif // RENTALFORM_H
