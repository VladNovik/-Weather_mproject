#include "weather.h"
#include "ui_weather.h"
#include <QtWidgets>

Weather::Weather(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Weather)
{
    ui->setupUi(this);

}


Weather::~Weather()
{
    delete ui;
}


void Weather::on_addCityButton_clicked()
{

}
