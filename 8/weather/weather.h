#ifndef WEATHER_H
#define WEATHER_H

#include <QWidget>
#include <QtWidgets>

namespace Ui {
class Weather;
}

class Weather : public QWidget
{
    Q_OBJECT

public:
    explicit Weather(QWidget *parent = nullptr);
    ~Weather();

private:
    Ui::Weather *ui;


private slots:
    void on_addCityButton_clicked();

};

#endif // WEATHER_H


