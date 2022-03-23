#ifndef RENTOGETHER_H
#define RENTOGETHER_H

#include <QMainWindow>

QT_BEGIN_NAMESPACE
namespace Ui { class rentogether; }
QT_END_NAMESPACE

class rentogether : public QMainWindow
{
    Q_OBJECT

    public:
        rentogether(QWidget *parent = nullptr);
        ~rentogether();

    private slots:
            void on_loginButton_clicked();

private:
            Ui::rentogether *ui;
};


#endif // RENTOGETHER_H
