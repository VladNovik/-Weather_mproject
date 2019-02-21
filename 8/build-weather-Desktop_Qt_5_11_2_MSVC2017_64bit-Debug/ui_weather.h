/********************************************************************************
** Form generated from reading UI file 'weather.ui'
**
** Created by: Qt User Interface Compiler version 5.11.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_WEATHER_H
#define UI_WEATHER_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QListWidget>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QTableView>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_Weather
{
public:
    QListWidget *nameCityList;
    QTableView *cityTableView;
    QLabel *nameCityTable;
    QLabel *label_2;
    QLineEdit *cityLineEdit;
    QPushButton *addCityButton;
    QPushButton *deleteCityButton;
    QPushButton *refreshCityList;
    QPushButton *closeButton;

    void setupUi(QWidget *Weather)
    {
        if (Weather->objectName().isEmpty())
            Weather->setObjectName(QStringLiteral("Weather"));
        Weather->resize(600, 300);
        nameCityList = new QListWidget(Weather);
        nameCityList->setObjectName(QStringLiteral("nameCityList"));
        nameCityList->setGeometry(QRect(420, 30, 161, 221));
        cityTableView = new QTableView(Weather);
        cityTableView->setObjectName(QStringLiteral("cityTableView"));
        cityTableView->setGeometry(QRect(20, 30, 381, 221));
        nameCityTable = new QLabel(Weather);
        nameCityTable->setObjectName(QStringLiteral("nameCityTable"));
        nameCityTable->setGeometry(QRect(20, 10, 47, 13));
        label_2 = new QLabel(Weather);
        label_2->setObjectName(QStringLiteral("label_2"));
        label_2->setGeometry(QRect(420, 10, 47, 13));
        cityLineEdit = new QLineEdit(Weather);
        cityLineEdit->setObjectName(QStringLiteral("cityLineEdit"));
        cityLineEdit->setGeometry(QRect(20, 260, 113, 20));
        addCityButton = new QPushButton(Weather);
        addCityButton->setObjectName(QStringLiteral("addCityButton"));
        addCityButton->setGeometry(QRect(140, 260, 75, 23));
        deleteCityButton = new QPushButton(Weather);
        deleteCityButton->setObjectName(QStringLiteral("deleteCityButton"));
        deleteCityButton->setGeometry(QRect(220, 260, 75, 23));
        refreshCityList = new QPushButton(Weather);
        refreshCityList->setObjectName(QStringLiteral("refreshCityList"));
        refreshCityList->setGeometry(QRect(300, 260, 75, 23));
        closeButton = new QPushButton(Weather);
        closeButton->setObjectName(QStringLiteral("closeButton"));
        closeButton->setGeometry(QRect(500, 260, 75, 23));

        retranslateUi(Weather);

        QMetaObject::connectSlotsByName(Weather);
    } // setupUi

    void retranslateUi(QWidget *Weather)
    {
        Weather->setWindowTitle(QApplication::translate("Weather", "Weather", nullptr));
        nameCityTable->setText(QApplication::translate("Weather", "Weather", nullptr));
        label_2->setText(QApplication::translate("Weather", "City", nullptr));
        addCityButton->setText(QApplication::translate("Weather", "Add", nullptr));
        deleteCityButton->setText(QApplication::translate("Weather", "Delete", nullptr));
        refreshCityList->setText(QApplication::translate("Weather", "Refresh", nullptr));
        closeButton->setText(QApplication::translate("Weather", "Close", nullptr));
    } // retranslateUi

};

namespace Ui {
    class Weather: public Ui_Weather {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_WEATHER_H
