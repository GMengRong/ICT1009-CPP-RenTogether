/********************************************************************************
** Form generated from reading UI file 'secdialog.ui'
**
** Created by: Qt User Interface Compiler version 6.3.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_SECDIALOG_H
#define UI_SECDIALOG_H

#include <QtCore/QDate>
#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QDateEdit>
#include <QtWidgets/QDialog>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QScrollArea>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QTabWidget>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_SecDialog
{
public:
    QTabWidget *tabWidget;
    QWidget *tab;
    QScrollArea *scrollArea;
    QWidget *scrollAreaWidgetContents;
    QLabel *label;
    QWidget *layoutWidget;
    QVBoxLayout *verticalLayout_4;
    QVBoxLayout *verticalLayout;
    QHBoxLayout *horizontalLayout;
    QLabel *vBrand;
    QLabel *Brand;
    QHBoxLayout *horizontalLayout_2;
    QLabel *vID;
    QLabel *VehicleID;
    QHBoxLayout *horizontalLayout_3;
    QLabel *vModel;
    QLabel *Model;
    QSpacerItem *verticalSpacer;
    QVBoxLayout *verticalLayout_2;
    QHBoxLayout *horizontalLayout_4;
    QLabel *vBrand_2;
    QLabel *Brand_2;
    QHBoxLayout *horizontalLayout_5;
    QLabel *vID_2;
    QLabel *VehicleID_2;
    QHBoxLayout *horizontalLayout_6;
    QLabel *vModel_2;
    QLabel *Model_2;
    QSpacerItem *verticalSpacer_2;
    QVBoxLayout *verticalLayout_3;
    QHBoxLayout *horizontalLayout_7;
    QLabel *vBrand_3;
    QLabel *Brand_3;
    QHBoxLayout *horizontalLayout_8;
    QLabel *vID_3;
    QLabel *VehicleID_3;
    QHBoxLayout *horizontalLayout_9;
    QLabel *vModel_3;
    QLabel *Model_3;
    QWidget *layoutWidget1;
    QHBoxLayout *horizontalLayout_15;
    QLabel *vSearch;
    QLineEdit *Search;
    QScrollArea *scrollArea_2;
    QWidget *scrollAreaWidgetContents_2;
    QLabel *label_2;
    QWidget *verticalLayoutWidget;
    QVBoxLayout *verticalLayout_5;
    QHBoxLayout *horizontalLayout_10;
    QLabel *vRID;
    QLabel *RentalID;
    QHBoxLayout *horizontalLayout_11;
    QLabel *vVehical;
    QLabel *RentedVehicle;
    QHBoxLayout *horizontalLayout_12;
    QLabel *vStart;
    QDateEdit *StartDate;
    QHBoxLayout *horizontalLayout_13;
    QLabel *vEnd;
    QDateEdit *EndDate;
    QHBoxLayout *horizontalLayout_14;
    QLabel *vPrice;
    QLabel *price;
    QWidget *Rent;

    void setupUi(QDialog *SecDialog)
    {
        if (SecDialog->objectName().isEmpty())
            SecDialog->setObjectName(QString::fromUtf8("SecDialog"));
        SecDialog->resize(945, 776);
        tabWidget = new QTabWidget(SecDialog);
        tabWidget->setObjectName(QString::fromUtf8("tabWidget"));
        tabWidget->setGeometry(QRect(10, 10, 641, 441));
        tab = new QWidget();
        tab->setObjectName(QString::fromUtf8("tab"));
        scrollArea = new QScrollArea(tab);
        scrollArea->setObjectName(QString::fromUtf8("scrollArea"));
        scrollArea->setGeometry(QRect(0, 0, 341, 341));
        scrollArea->setWidgetResizable(true);
        scrollAreaWidgetContents = new QWidget();
        scrollAreaWidgetContents->setObjectName(QString::fromUtf8("scrollAreaWidgetContents"));
        scrollAreaWidgetContents->setGeometry(QRect(0, 0, 339, 339));
        label = new QLabel(scrollAreaWidgetContents);
        label->setObjectName(QString::fromUtf8("label"));
        label->setGeometry(QRect(120, 20, 181, 16));
        layoutWidget = new QWidget(scrollAreaWidgetContents);
        layoutWidget->setObjectName(QString::fromUtf8("layoutWidget"));
        layoutWidget->setGeometry(QRect(60, 90, 221, 230));
        verticalLayout_4 = new QVBoxLayout(layoutWidget);
        verticalLayout_4->setObjectName(QString::fromUtf8("verticalLayout_4"));
        verticalLayout_4->setContentsMargins(0, 0, 0, 0);
        verticalLayout = new QVBoxLayout();
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        vBrand = new QLabel(layoutWidget);
        vBrand->setObjectName(QString::fromUtf8("vBrand"));

        horizontalLayout->addWidget(vBrand);

        Brand = new QLabel(layoutWidget);
        Brand->setObjectName(QString::fromUtf8("Brand"));

        horizontalLayout->addWidget(Brand);


        verticalLayout->addLayout(horizontalLayout);

        horizontalLayout_2 = new QHBoxLayout();
        horizontalLayout_2->setObjectName(QString::fromUtf8("horizontalLayout_2"));
        vID = new QLabel(layoutWidget);
        vID->setObjectName(QString::fromUtf8("vID"));

        horizontalLayout_2->addWidget(vID);

        VehicleID = new QLabel(layoutWidget);
        VehicleID->setObjectName(QString::fromUtf8("VehicleID"));

        horizontalLayout_2->addWidget(VehicleID);


        verticalLayout->addLayout(horizontalLayout_2);

        horizontalLayout_3 = new QHBoxLayout();
        horizontalLayout_3->setObjectName(QString::fromUtf8("horizontalLayout_3"));
        vModel = new QLabel(layoutWidget);
        vModel->setObjectName(QString::fromUtf8("vModel"));

        horizontalLayout_3->addWidget(vModel);

        Model = new QLabel(layoutWidget);
        Model->setObjectName(QString::fromUtf8("Model"));

        horizontalLayout_3->addWidget(Model);


        verticalLayout->addLayout(horizontalLayout_3);


        verticalLayout_4->addLayout(verticalLayout);

        verticalSpacer = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

        verticalLayout_4->addItem(verticalSpacer);

        verticalLayout_2 = new QVBoxLayout();
        verticalLayout_2->setObjectName(QString::fromUtf8("verticalLayout_2"));
        horizontalLayout_4 = new QHBoxLayout();
        horizontalLayout_4->setObjectName(QString::fromUtf8("horizontalLayout_4"));
        vBrand_2 = new QLabel(layoutWidget);
        vBrand_2->setObjectName(QString::fromUtf8("vBrand_2"));

        horizontalLayout_4->addWidget(vBrand_2);

        Brand_2 = new QLabel(layoutWidget);
        Brand_2->setObjectName(QString::fromUtf8("Brand_2"));

        horizontalLayout_4->addWidget(Brand_2);


        verticalLayout_2->addLayout(horizontalLayout_4);

        horizontalLayout_5 = new QHBoxLayout();
        horizontalLayout_5->setObjectName(QString::fromUtf8("horizontalLayout_5"));
        vID_2 = new QLabel(layoutWidget);
        vID_2->setObjectName(QString::fromUtf8("vID_2"));

        horizontalLayout_5->addWidget(vID_2);

        VehicleID_2 = new QLabel(layoutWidget);
        VehicleID_2->setObjectName(QString::fromUtf8("VehicleID_2"));

        horizontalLayout_5->addWidget(VehicleID_2);


        verticalLayout_2->addLayout(horizontalLayout_5);

        horizontalLayout_6 = new QHBoxLayout();
        horizontalLayout_6->setObjectName(QString::fromUtf8("horizontalLayout_6"));
        vModel_2 = new QLabel(layoutWidget);
        vModel_2->setObjectName(QString::fromUtf8("vModel_2"));

        horizontalLayout_6->addWidget(vModel_2);

        Model_2 = new QLabel(layoutWidget);
        Model_2->setObjectName(QString::fromUtf8("Model_2"));

        horizontalLayout_6->addWidget(Model_2);


        verticalLayout_2->addLayout(horizontalLayout_6);


        verticalLayout_4->addLayout(verticalLayout_2);

        verticalSpacer_2 = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

        verticalLayout_4->addItem(verticalSpacer_2);

        verticalLayout_3 = new QVBoxLayout();
        verticalLayout_3->setObjectName(QString::fromUtf8("verticalLayout_3"));
        horizontalLayout_7 = new QHBoxLayout();
        horizontalLayout_7->setObjectName(QString::fromUtf8("horizontalLayout_7"));
        vBrand_3 = new QLabel(layoutWidget);
        vBrand_3->setObjectName(QString::fromUtf8("vBrand_3"));

        horizontalLayout_7->addWidget(vBrand_3);

        Brand_3 = new QLabel(layoutWidget);
        Brand_3->setObjectName(QString::fromUtf8("Brand_3"));

        horizontalLayout_7->addWidget(Brand_3);


        verticalLayout_3->addLayout(horizontalLayout_7);

        horizontalLayout_8 = new QHBoxLayout();
        horizontalLayout_8->setObjectName(QString::fromUtf8("horizontalLayout_8"));
        vID_3 = new QLabel(layoutWidget);
        vID_3->setObjectName(QString::fromUtf8("vID_3"));

        horizontalLayout_8->addWidget(vID_3);

        VehicleID_3 = new QLabel(layoutWidget);
        VehicleID_3->setObjectName(QString::fromUtf8("VehicleID_3"));

        horizontalLayout_8->addWidget(VehicleID_3);


        verticalLayout_3->addLayout(horizontalLayout_8);

        horizontalLayout_9 = new QHBoxLayout();
        horizontalLayout_9->setObjectName(QString::fromUtf8("horizontalLayout_9"));
        vModel_3 = new QLabel(layoutWidget);
        vModel_3->setObjectName(QString::fromUtf8("vModel_3"));

        horizontalLayout_9->addWidget(vModel_3);

        Model_3 = new QLabel(layoutWidget);
        Model_3->setObjectName(QString::fromUtf8("Model_3"));

        horizontalLayout_9->addWidget(Model_3);


        verticalLayout_3->addLayout(horizontalLayout_9);


        verticalLayout_4->addLayout(verticalLayout_3);

        layoutWidget1 = new QWidget(scrollAreaWidgetContents);
        layoutWidget1->setObjectName(QString::fromUtf8("layoutWidget1"));
        layoutWidget1->setGeometry(QRect(80, 50, 171, 26));
        horizontalLayout_15 = new QHBoxLayout(layoutWidget1);
        horizontalLayout_15->setObjectName(QString::fromUtf8("horizontalLayout_15"));
        horizontalLayout_15->setContentsMargins(0, 0, 0, 0);
        vSearch = new QLabel(layoutWidget1);
        vSearch->setObjectName(QString::fromUtf8("vSearch"));

        horizontalLayout_15->addWidget(vSearch);

        Search = new QLineEdit(layoutWidget1);
        Search->setObjectName(QString::fromUtf8("Search"));

        horizontalLayout_15->addWidget(Search);

        scrollArea->setWidget(scrollAreaWidgetContents);
        scrollArea_2 = new QScrollArea(tab);
        scrollArea_2->setObjectName(QString::fromUtf8("scrollArea_2"));
        scrollArea_2->setGeometry(QRect(340, 0, 371, 311));
        scrollArea_2->setWidgetResizable(true);
        scrollAreaWidgetContents_2 = new QWidget();
        scrollAreaWidgetContents_2->setObjectName(QString::fromUtf8("scrollAreaWidgetContents_2"));
        scrollAreaWidgetContents_2->setGeometry(QRect(0, 0, 369, 309));
        label_2 = new QLabel(scrollAreaWidgetContents_2);
        label_2->setObjectName(QString::fromUtf8("label_2"));
        label_2->setGeometry(QRect(80, 20, 131, 20));
        verticalLayoutWidget = new QWidget(scrollAreaWidgetContents_2);
        verticalLayoutWidget->setObjectName(QString::fromUtf8("verticalLayoutWidget"));
        verticalLayoutWidget->setGeometry(QRect(20, 50, 201, 181));
        verticalLayout_5 = new QVBoxLayout(verticalLayoutWidget);
        verticalLayout_5->setObjectName(QString::fromUtf8("verticalLayout_5"));
        verticalLayout_5->setContentsMargins(0, 0, 0, 0);
        horizontalLayout_10 = new QHBoxLayout();
        horizontalLayout_10->setObjectName(QString::fromUtf8("horizontalLayout_10"));
        vRID = new QLabel(verticalLayoutWidget);
        vRID->setObjectName(QString::fromUtf8("vRID"));

        horizontalLayout_10->addWidget(vRID);

        RentalID = new QLabel(verticalLayoutWidget);
        RentalID->setObjectName(QString::fromUtf8("RentalID"));

        horizontalLayout_10->addWidget(RentalID);


        verticalLayout_5->addLayout(horizontalLayout_10);

        horizontalLayout_11 = new QHBoxLayout();
        horizontalLayout_11->setObjectName(QString::fromUtf8("horizontalLayout_11"));
        vVehical = new QLabel(verticalLayoutWidget);
        vVehical->setObjectName(QString::fromUtf8("vVehical"));

        horizontalLayout_11->addWidget(vVehical);

        RentedVehicle = new QLabel(verticalLayoutWidget);
        RentedVehicle->setObjectName(QString::fromUtf8("RentedVehicle"));

        horizontalLayout_11->addWidget(RentedVehicle);


        verticalLayout_5->addLayout(horizontalLayout_11);

        horizontalLayout_12 = new QHBoxLayout();
        horizontalLayout_12->setObjectName(QString::fromUtf8("horizontalLayout_12"));
        vStart = new QLabel(verticalLayoutWidget);
        vStart->setObjectName(QString::fromUtf8("vStart"));

        horizontalLayout_12->addWidget(vStart);

        StartDate = new QDateEdit(verticalLayoutWidget);
        StartDate->setObjectName(QString::fromUtf8("StartDate"));
        StartDate->setDate(QDate(2022, 4, 1));

        horizontalLayout_12->addWidget(StartDate);


        verticalLayout_5->addLayout(horizontalLayout_12);

        horizontalLayout_13 = new QHBoxLayout();
        horizontalLayout_13->setObjectName(QString::fromUtf8("horizontalLayout_13"));
        vEnd = new QLabel(verticalLayoutWidget);
        vEnd->setObjectName(QString::fromUtf8("vEnd"));

        horizontalLayout_13->addWidget(vEnd);

        EndDate = new QDateEdit(verticalLayoutWidget);
        EndDate->setObjectName(QString::fromUtf8("EndDate"));
        EndDate->setDate(QDate(2022, 4, 1));

        horizontalLayout_13->addWidget(EndDate);


        verticalLayout_5->addLayout(horizontalLayout_13);

        horizontalLayout_14 = new QHBoxLayout();
        horizontalLayout_14->setObjectName(QString::fromUtf8("horizontalLayout_14"));
        vPrice = new QLabel(verticalLayoutWidget);
        vPrice->setObjectName(QString::fromUtf8("vPrice"));

        horizontalLayout_14->addWidget(vPrice);

        price = new QLabel(verticalLayoutWidget);
        price->setObjectName(QString::fromUtf8("price"));

        horizontalLayout_14->addWidget(price);


        verticalLayout_5->addLayout(horizontalLayout_14);

        scrollArea_2->setWidget(scrollAreaWidgetContents_2);
        tabWidget->addTab(tab, QString());
        Rent = new QWidget();
        Rent->setObjectName(QString::fromUtf8("Rent"));
        tabWidget->addTab(Rent, QString());

        retranslateUi(SecDialog);

        tabWidget->setCurrentIndex(0);


        QMetaObject::connectSlotsByName(SecDialog);
    } // setupUi

    void retranslateUi(QDialog *SecDialog)
    {
        SecDialog->setWindowTitle(QCoreApplication::translate("SecDialog", "Dialog", nullptr));
        label->setText(QCoreApplication::translate("SecDialog", "--- Vehicles For Rent ----", nullptr));
        vBrand->setText(QCoreApplication::translate("SecDialog", "Brand:", nullptr));
        Brand->setText(QCoreApplication::translate("SecDialog", "displaynamehere", nullptr));
        vID->setText(QCoreApplication::translate("SecDialog", "Vehicle ID:", nullptr));
        VehicleID->setText(QCoreApplication::translate("SecDialog", "display VID here", nullptr));
        vModel->setText(QCoreApplication::translate("SecDialog", "Model:", nullptr));
        Model->setText(QCoreApplication::translate("SecDialog", "displaymodelhere", nullptr));
        vBrand_2->setText(QCoreApplication::translate("SecDialog", "Brand:", nullptr));
        Brand_2->setText(QCoreApplication::translate("SecDialog", "displaynamehere", nullptr));
        vID_2->setText(QCoreApplication::translate("SecDialog", "Vehicle ID:", nullptr));
        VehicleID_2->setText(QCoreApplication::translate("SecDialog", "display VID here", nullptr));
        vModel_2->setText(QCoreApplication::translate("SecDialog", "Model:", nullptr));
        Model_2->setText(QCoreApplication::translate("SecDialog", "displaymodelhere", nullptr));
        vBrand_3->setText(QCoreApplication::translate("SecDialog", "Brand:", nullptr));
        Brand_3->setText(QCoreApplication::translate("SecDialog", "displaynamehere", nullptr));
        vID_3->setText(QCoreApplication::translate("SecDialog", "Vehicle ID:", nullptr));
        VehicleID_3->setText(QCoreApplication::translate("SecDialog", "display VID here", nullptr));
        vModel_3->setText(QCoreApplication::translate("SecDialog", "Model:", nullptr));
        Model_3->setText(QCoreApplication::translate("SecDialog", "displaymodelhere", nullptr));
        vSearch->setText(QCoreApplication::translate("SecDialog", "Search:         ", nullptr));
        label_2->setText(QCoreApplication::translate("SecDialog", "--- Rental Form ---", nullptr));
        vRID->setText(QCoreApplication::translate("SecDialog", "Rent ID:", nullptr));
        RentalID->setText(QCoreApplication::translate("SecDialog", "displaynamehere", nullptr));
        vVehical->setText(QCoreApplication::translate("SecDialog", "Vehicle:", nullptr));
        RentedVehicle->setText(QCoreApplication::translate("SecDialog", "display VID here", nullptr));
        vStart->setText(QCoreApplication::translate("SecDialog", "Start Date:", nullptr));
        vEnd->setText(QCoreApplication::translate("SecDialog", "End Date:", nullptr));
        vPrice->setText(QCoreApplication::translate("SecDialog", "Price:", nullptr));
        price->setText(QCoreApplication::translate("SecDialog", "display price here", nullptr));
        tabWidget->setTabText(tabWidget->indexOf(tab), QCoreApplication::translate("SecDialog", "Rents", nullptr));
        tabWidget->setTabText(tabWidget->indexOf(Rent), QCoreApplication::translate("SecDialog", "View Rental", nullptr));
    } // retranslateUi

};

namespace Ui {
    class SecDialog: public Ui_SecDialog {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_SECDIALOG_H
