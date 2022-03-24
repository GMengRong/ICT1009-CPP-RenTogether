/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created by: Qt User Interface Compiler version 6.2.4
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QGroupBox>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QScrollArea>
#include <QtWidgets/QSpacerItem>
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
    QHBoxLayout *usernameLayout;
    QLabel *userLabel;
    QLineEdit *userInput;
    QHBoxLayout *passwordLayout;
    QLabel *passwdLabel;
    QLineEdit *passwdInput;
    QPushButton *loginButton;
    QScrollArea *scrollArea;
    QWidget *scrollAreaWidgetContents;
    QLabel *label_4;
    QWidget *layoutWidget1;
    QVBoxLayout *verticalLayout_4;
    QVBoxLayout *verticalLayout_2;
    QHBoxLayout *horizontalLayout_3;
    QLabel *vBrand;
    QLabel *Brand;
    QHBoxLayout *horizontalLayout_4;
    QLabel *vID;
    QLabel *VehicleID;
    QHBoxLayout *horizontalLayout_5;
    QLabel *vModel;
    QLabel *Model;
    QSpacerItem *verticalSpacer;
    QVBoxLayout *verticalLayout_3;
    QHBoxLayout *horizontalLayout_6;
    QLabel *vBrand_2;
    QLabel *Brand_2;
    QHBoxLayout *horizontalLayout_7;
    QLabel *vID_2;
    QLabel *VehicleID_2;
    QHBoxLayout *horizontalLayout_8;
    QLabel *vModel_2;
    QLabel *Model_2;
    QSpacerItem *verticalSpacer_2;
    QVBoxLayout *verticalLayout_5;
    QHBoxLayout *horizontalLayout_9;
    QLabel *vBrand_3;
    QLabel *Brand_3;
    QHBoxLayout *horizontalLayout_10;
    QLabel *vID_3;
    QLabel *VehicleID_3;
    QHBoxLayout *horizontalLayout_11;
    QLabel *vModel_3;
    QLabel *Model_3;
    QWidget *layoutWidget_2;
    QHBoxLayout *horizontalLayout_15;
    QLabel *vSearch;
    QLineEdit *Search;
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
        signinBox->setGeometry(QRect(100, 280, 201, 131));
        layoutWidget = new QWidget(signinBox);
        layoutWidget->setObjectName(QString::fromUtf8("layoutWidget"));
        layoutWidget->setGeometry(QRect(10, 20, 181, 101));
        verticalLayout = new QVBoxLayout(layoutWidget);
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        verticalLayout->setContentsMargins(0, 0, 0, 0);
        usernameLayout = new QHBoxLayout();
        usernameLayout->setObjectName(QString::fromUtf8("usernameLayout"));
        userLabel = new QLabel(layoutWidget);
        userLabel->setObjectName(QString::fromUtf8("userLabel"));

        usernameLayout->addWidget(userLabel);

        userInput = new QLineEdit(layoutWidget);
        userInput->setObjectName(QString::fromUtf8("userInput"));

        usernameLayout->addWidget(userInput);


        verticalLayout->addLayout(usernameLayout);

        passwordLayout = new QHBoxLayout();
        passwordLayout->setObjectName(QString::fromUtf8("passwordLayout"));
        passwdLabel = new QLabel(layoutWidget);
        passwdLabel->setObjectName(QString::fromUtf8("passwdLabel"));

        passwordLayout->addWidget(passwdLabel);

        passwdInput = new QLineEdit(layoutWidget);
        passwdInput->setObjectName(QString::fromUtf8("passwdInput"));

        passwordLayout->addWidget(passwdInput);


        verticalLayout->addLayout(passwordLayout);

        loginButton = new QPushButton(layoutWidget);
        loginButton->setObjectName(QString::fromUtf8("loginButton"));

        verticalLayout->addWidget(loginButton);

        scrollArea = new QScrollArea(centralwidget);
        scrollArea->setObjectName(QString::fromUtf8("scrollArea"));
        scrollArea->setGeometry(QRect(400, 0, 400, 557));
        scrollArea->setWidgetResizable(true);
        scrollAreaWidgetContents = new QWidget();
        scrollAreaWidgetContents->setObjectName(QString::fromUtf8("scrollAreaWidgetContents"));
        scrollAreaWidgetContents->setGeometry(QRect(0, 0, 398, 555));
        label_4 = new QLabel(scrollAreaWidgetContents);
        label_4->setObjectName(QString::fromUtf8("label_4"));
        label_4->setGeometry(QRect(110, 20, 141, 16));
        layoutWidget1 = new QWidget(scrollAreaWidgetContents);
        layoutWidget1->setObjectName(QString::fromUtf8("layoutWidget1"));
        layoutWidget1->setGeometry(QRect(60, 90, 221, 230));
        verticalLayout_4 = new QVBoxLayout(layoutWidget1);
        verticalLayout_4->setObjectName(QString::fromUtf8("verticalLayout_4"));
        verticalLayout_4->setContentsMargins(0, 0, 0, 0);
        verticalLayout_2 = new QVBoxLayout();
        verticalLayout_2->setObjectName(QString::fromUtf8("verticalLayout_2"));
        horizontalLayout_3 = new QHBoxLayout();
        horizontalLayout_3->setObjectName(QString::fromUtf8("horizontalLayout_3"));
        vBrand = new QLabel(layoutWidget1);
        vBrand->setObjectName(QString::fromUtf8("vBrand"));

        horizontalLayout_3->addWidget(vBrand);

        Brand = new QLabel(layoutWidget1);
        Brand->setObjectName(QString::fromUtf8("Brand"));

        horizontalLayout_3->addWidget(Brand);


        verticalLayout_2->addLayout(horizontalLayout_3);

        horizontalLayout_4 = new QHBoxLayout();
        horizontalLayout_4->setObjectName(QString::fromUtf8("horizontalLayout_4"));
        vID = new QLabel(layoutWidget1);
        vID->setObjectName(QString::fromUtf8("vID"));

        horizontalLayout_4->addWidget(vID);

        VehicleID = new QLabel(layoutWidget1);
        VehicleID->setObjectName(QString::fromUtf8("VehicleID"));

        horizontalLayout_4->addWidget(VehicleID);


        verticalLayout_2->addLayout(horizontalLayout_4);

        horizontalLayout_5 = new QHBoxLayout();
        horizontalLayout_5->setObjectName(QString::fromUtf8("horizontalLayout_5"));
        vModel = new QLabel(layoutWidget1);
        vModel->setObjectName(QString::fromUtf8("vModel"));

        horizontalLayout_5->addWidget(vModel);

        Model = new QLabel(layoutWidget1);
        Model->setObjectName(QString::fromUtf8("Model"));

        horizontalLayout_5->addWidget(Model);


        verticalLayout_2->addLayout(horizontalLayout_5);


        verticalLayout_4->addLayout(verticalLayout_2);

        verticalSpacer = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

        verticalLayout_4->addItem(verticalSpacer);

        verticalLayout_3 = new QVBoxLayout();
        verticalLayout_3->setObjectName(QString::fromUtf8("verticalLayout_3"));
        horizontalLayout_6 = new QHBoxLayout();
        horizontalLayout_6->setObjectName(QString::fromUtf8("horizontalLayout_6"));
        vBrand_2 = new QLabel(layoutWidget1);
        vBrand_2->setObjectName(QString::fromUtf8("vBrand_2"));

        horizontalLayout_6->addWidget(vBrand_2);

        Brand_2 = new QLabel(layoutWidget1);
        Brand_2->setObjectName(QString::fromUtf8("Brand_2"));

        horizontalLayout_6->addWidget(Brand_2);


        verticalLayout_3->addLayout(horizontalLayout_6);

        horizontalLayout_7 = new QHBoxLayout();
        horizontalLayout_7->setObjectName(QString::fromUtf8("horizontalLayout_7"));
        vID_2 = new QLabel(layoutWidget1);
        vID_2->setObjectName(QString::fromUtf8("vID_2"));

        horizontalLayout_7->addWidget(vID_2);

        VehicleID_2 = new QLabel(layoutWidget1);
        VehicleID_2->setObjectName(QString::fromUtf8("VehicleID_2"));

        horizontalLayout_7->addWidget(VehicleID_2);


        verticalLayout_3->addLayout(horizontalLayout_7);

        horizontalLayout_8 = new QHBoxLayout();
        horizontalLayout_8->setObjectName(QString::fromUtf8("horizontalLayout_8"));
        vModel_2 = new QLabel(layoutWidget1);
        vModel_2->setObjectName(QString::fromUtf8("vModel_2"));

        horizontalLayout_8->addWidget(vModel_2);

        Model_2 = new QLabel(layoutWidget1);
        Model_2->setObjectName(QString::fromUtf8("Model_2"));

        horizontalLayout_8->addWidget(Model_2);


        verticalLayout_3->addLayout(horizontalLayout_8);


        verticalLayout_4->addLayout(verticalLayout_3);

        verticalSpacer_2 = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

        verticalLayout_4->addItem(verticalSpacer_2);

        verticalLayout_5 = new QVBoxLayout();
        verticalLayout_5->setObjectName(QString::fromUtf8("verticalLayout_5"));
        horizontalLayout_9 = new QHBoxLayout();
        horizontalLayout_9->setObjectName(QString::fromUtf8("horizontalLayout_9"));
        vBrand_3 = new QLabel(layoutWidget1);
        vBrand_3->setObjectName(QString::fromUtf8("vBrand_3"));

        horizontalLayout_9->addWidget(vBrand_3);

        Brand_3 = new QLabel(layoutWidget1);
        Brand_3->setObjectName(QString::fromUtf8("Brand_3"));

        horizontalLayout_9->addWidget(Brand_3);


        verticalLayout_5->addLayout(horizontalLayout_9);

        horizontalLayout_10 = new QHBoxLayout();
        horizontalLayout_10->setObjectName(QString::fromUtf8("horizontalLayout_10"));
        vID_3 = new QLabel(layoutWidget1);
        vID_3->setObjectName(QString::fromUtf8("vID_3"));

        horizontalLayout_10->addWidget(vID_3);

        VehicleID_3 = new QLabel(layoutWidget1);
        VehicleID_3->setObjectName(QString::fromUtf8("VehicleID_3"));

        horizontalLayout_10->addWidget(VehicleID_3);


        verticalLayout_5->addLayout(horizontalLayout_10);

        horizontalLayout_11 = new QHBoxLayout();
        horizontalLayout_11->setObjectName(QString::fromUtf8("horizontalLayout_11"));
        vModel_3 = new QLabel(layoutWidget1);
        vModel_3->setObjectName(QString::fromUtf8("vModel_3"));

        horizontalLayout_11->addWidget(vModel_3);

        Model_3 = new QLabel(layoutWidget1);
        Model_3->setObjectName(QString::fromUtf8("Model_3"));

        horizontalLayout_11->addWidget(Model_3);


        verticalLayout_5->addLayout(horizontalLayout_11);


        verticalLayout_4->addLayout(verticalLayout_5);

        layoutWidget_2 = new QWidget(scrollAreaWidgetContents);
        layoutWidget_2->setObjectName(QString::fromUtf8("layoutWidget_2"));
        layoutWidget_2->setGeometry(QRect(80, 50, 171, 26));
        horizontalLayout_15 = new QHBoxLayout(layoutWidget_2);
        horizontalLayout_15->setObjectName(QString::fromUtf8("horizontalLayout_15"));
        horizontalLayout_15->setContentsMargins(0, 0, 0, 0);
        vSearch = new QLabel(layoutWidget_2);
        vSearch->setObjectName(QString::fromUtf8("vSearch"));

        horizontalLayout_15->addWidget(vSearch);

        Search = new QLineEdit(layoutWidget_2);
        Search->setObjectName(QString::fromUtf8("Search"));

        horizontalLayout_15->addWidget(Search);

        scrollArea->setWidget(scrollAreaWidgetContents);
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
        userLabel->setText(QCoreApplication::translate("MainWindow", "Username", nullptr));
        passwdLabel->setText(QCoreApplication::translate("MainWindow", "Password", nullptr));
        loginButton->setText(QCoreApplication::translate("MainWindow", "Login", nullptr));
        label_4->setText(QCoreApplication::translate("MainWindow", "--- Vehicles For Rent ----", nullptr));
        vBrand->setText(QCoreApplication::translate("MainWindow", "Brand:", nullptr));
        Brand->setText(QCoreApplication::translate("MainWindow", "displaynamehere", nullptr));
        vID->setText(QCoreApplication::translate("MainWindow", "Vehicle ID:", nullptr));
        VehicleID->setText(QCoreApplication::translate("MainWindow", "display VID here", nullptr));
        vModel->setText(QCoreApplication::translate("MainWindow", "Model:", nullptr));
        Model->setText(QCoreApplication::translate("MainWindow", "displaymodelhere", nullptr));
        vBrand_2->setText(QCoreApplication::translate("MainWindow", "Brand:", nullptr));
        Brand_2->setText(QCoreApplication::translate("MainWindow", "displaynamehere", nullptr));
        vID_2->setText(QCoreApplication::translate("MainWindow", "Vehicle ID:", nullptr));
        VehicleID_2->setText(QCoreApplication::translate("MainWindow", "display VID here", nullptr));
        vModel_2->setText(QCoreApplication::translate("MainWindow", "Model:", nullptr));
        Model_2->setText(QCoreApplication::translate("MainWindow", "displaymodelhere", nullptr));
        vBrand_3->setText(QCoreApplication::translate("MainWindow", "Brand:", nullptr));
        Brand_3->setText(QCoreApplication::translate("MainWindow", "displaynamehere", nullptr));
        vID_3->setText(QCoreApplication::translate("MainWindow", "Vehicle ID:", nullptr));
        VehicleID_3->setText(QCoreApplication::translate("MainWindow", "display VID here", nullptr));
        vModel_3->setText(QCoreApplication::translate("MainWindow", "Model:", nullptr));
        Model_3->setText(QCoreApplication::translate("MainWindow", "displaymodelhere", nullptr));
        vSearch->setText(QCoreApplication::translate("MainWindow", "Search:         ", nullptr));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
