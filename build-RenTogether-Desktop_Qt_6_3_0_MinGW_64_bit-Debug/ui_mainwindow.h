/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created by: Qt User Interface Compiler version 6.3.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QGroupBox>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QWidget *centralwidget;
    QGroupBox *signinBox;
    QWidget *layoutWidget;
    QVBoxLayout *verticalLayout;
    QVBoxLayout *verticalLayout_2;
    QLabel *userLabel;
    QLineEdit *userInput;
    QVBoxLayout *verticalLayout_3;
    QLabel *passwdLabel;
    QLineEdit *passwdInput;
    QPushButton *loginButton;
    QLabel *title;
    QMenuBar *menubar;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName(QString::fromUtf8("MainWindow"));
        MainWindow->resize(800, 600);
        centralwidget = new QWidget(MainWindow);
        centralwidget->setObjectName(QString::fromUtf8("centralwidget"));
        signinBox = new QGroupBox(centralwidget);
        signinBox->setObjectName(QString::fromUtf8("signinBox"));
        signinBox->setGeometry(QRect(200, 175, 400, 250));
        signinBox->setAlignment(Qt::AlignLeading|Qt::AlignLeft|Qt::AlignVCenter);
        layoutWidget = new QWidget(signinBox);
        layoutWidget->setObjectName(QString::fromUtf8("layoutWidget"));
        layoutWidget->setGeometry(QRect(10, 30, 381, 191));
        verticalLayout = new QVBoxLayout(layoutWidget);
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        verticalLayout->setContentsMargins(0, 0, 0, 0);
        verticalLayout_2 = new QVBoxLayout();
        verticalLayout_2->setObjectName(QString::fromUtf8("verticalLayout_2"));
        userLabel = new QLabel(layoutWidget);
        userLabel->setObjectName(QString::fromUtf8("userLabel"));
        QSizePolicy sizePolicy(QSizePolicy::Preferred, QSizePolicy::Fixed);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(userLabel->sizePolicy().hasHeightForWidth());
        userLabel->setSizePolicy(sizePolicy);

        verticalLayout_2->addWidget(userLabel);

        userInput = new QLineEdit(layoutWidget);
        userInput->setObjectName(QString::fromUtf8("userInput"));
        userInput->setEnabled(true);
        QSizePolicy sizePolicy1(QSizePolicy::Expanding, QSizePolicy::Fixed);
        sizePolicy1.setHorizontalStretch(0);
        sizePolicy1.setVerticalStretch(0);
        sizePolicy1.setHeightForWidth(userInput->sizePolicy().hasHeightForWidth());
        userInput->setSizePolicy(sizePolicy1);

        verticalLayout_2->addWidget(userInput);


        verticalLayout->addLayout(verticalLayout_2);

        verticalLayout_3 = new QVBoxLayout();
        verticalLayout_3->setObjectName(QString::fromUtf8("verticalLayout_3"));
        passwdLabel = new QLabel(layoutWidget);
        passwdLabel->setObjectName(QString::fromUtf8("passwdLabel"));
        sizePolicy.setHeightForWidth(passwdLabel->sizePolicy().hasHeightForWidth());
        passwdLabel->setSizePolicy(sizePolicy);

        verticalLayout_3->addWidget(passwdLabel);

        passwdInput = new QLineEdit(layoutWidget);
        passwdInput->setObjectName(QString::fromUtf8("passwdInput"));

        verticalLayout_3->addWidget(passwdInput);


        verticalLayout->addLayout(verticalLayout_3);

        loginButton = new QPushButton(layoutWidget);
        loginButton->setObjectName(QString::fromUtf8("loginButton"));

        verticalLayout->addWidget(loginButton);

        title = new QLabel(centralwidget);
        title->setObjectName(QString::fromUtf8("title"));
        title->setGeometry(QRect(0, 30, 801, 131));
        QFont font;
        font.setFamilies({QString::fromUtf8("Facon")});
        font.setPointSize(48);
        font.setBold(true);
        font.setItalic(true);
        title->setFont(font);
        title->setAlignment(Qt::AlignCenter);
        MainWindow->setCentralWidget(centralwidget);
        menubar = new QMenuBar(MainWindow);
        menubar->setObjectName(QString::fromUtf8("menubar"));
        menubar->setGeometry(QRect(0, 0, 800, 21));
        MainWindow->setMenuBar(menubar);
        statusbar = new QStatusBar(MainWindow);
        statusbar->setObjectName(QString::fromUtf8("statusbar"));
        statusbar->setEnabled(true);
        MainWindow->setStatusBar(statusbar);

        retranslateUi(MainWindow);

        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QCoreApplication::translate("MainWindow", "MainWindow", nullptr));
        signinBox->setTitle(QCoreApplication::translate("MainWindow", "Sign in", nullptr));
        userLabel->setText(QCoreApplication::translate("MainWindow", "Username:", nullptr));
        passwdLabel->setText(QCoreApplication::translate("MainWindow", "Password", nullptr));
        loginButton->setText(QCoreApplication::translate("MainWindow", "Login", nullptr));
        title->setText(QCoreApplication::translate("MainWindow", "RenTogether", nullptr));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
