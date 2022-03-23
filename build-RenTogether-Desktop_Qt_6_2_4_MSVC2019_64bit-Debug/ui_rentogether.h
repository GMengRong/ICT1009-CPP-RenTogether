/********************************************************************************
** Form generated from reading UI file 'rentogether.ui'
**
** Created by: Qt User Interface Compiler version 6.2.4
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_RENTOGETHER_H
#define UI_RENTOGETHER_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QLabel>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_rentogether
{
public:
    QWidget *centralwidget;
    QPushButton *loginButton;
    QLabel *title;
    QStatusBar *statusbar;
    QMenuBar *menubar;

    void setupUi(QMainWindow *rentogether)
    {
        if (rentogether->objectName().isEmpty())
            rentogether->setObjectName(QString::fromUtf8("rentogether"));
        rentogether->resize(800, 600);
        centralwidget = new QWidget(rentogether);
        centralwidget->setObjectName(QString::fromUtf8("centralwidget"));
        loginButton = new QPushButton(centralwidget);
        loginButton->setObjectName(QString::fromUtf8("loginButton"));
        loginButton->setGeometry(QRect(360, 270, 80, 24));
        title = new QLabel(centralwidget);
        title->setObjectName(QString::fromUtf8("title"));
        title->setGeometry(QRect(140, 30, 531, 171));
        QFont font;
        font.setPointSize(48);
        title->setFont(font);
        rentogether->setCentralWidget(centralwidget);
        statusbar = new QStatusBar(rentogether);
        statusbar->setObjectName(QString::fromUtf8("statusbar"));
        rentogether->setStatusBar(statusbar);
        menubar = new QMenuBar(rentogether);
        menubar->setObjectName(QString::fromUtf8("menubar"));
        menubar->setGeometry(QRect(0, 0, 800, 21));
        rentogether->setMenuBar(menubar);

        retranslateUi(rentogether);

        QMetaObject::connectSlotsByName(rentogether);
    } // setupUi

    void retranslateUi(QMainWindow *rentogether)
    {
        rentogether->setWindowTitle(QCoreApplication::translate("rentogether", "rentogether", nullptr));
        loginButton->setText(QCoreApplication::translate("rentogether", "Login", nullptr));
        title->setText(QCoreApplication::translate("rentogether", "RenTogether", nullptr));
    } // retranslateUi

};

namespace Ui {
    class rentogether: public Ui_rentogether {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_RENTOGETHER_H
