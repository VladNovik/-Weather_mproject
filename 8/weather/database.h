#ifndef DATABASE_H
#define DATABASE_H

#include <QObject>
#include <QSql>
#include <QSqlQuery>
#include <QSqlError>
#include <QSqlDatabase>
#include <QFile>
#include <QDate>
#include <QDebug>


#define DATABASE_HOSTNAME   "ExampleDataBase"
#define DATABASE_NAME       "DataBase.db"

#define WEATHER                  "WeatherTable"
#define WEATHER_DATE             "Date"
#define WEATHER_TEMP             "NormalTemp"
#define WEATHER_TEMPMIN          "MinTemp"
#define WEATHER_TEMPMAX          "MaxTemp"
#define WEATHER_RAIN             "WeatherRain"

class DataBase : public QObject
{
    Q_OBJECT
public:
    explicit DataBase(QObject *parent = 0);
    ~DataBase();
    //Подключение к базе данных и вставка записей в таблицу

    void connectToDataBase();
    bool inserIntoDeviceTable(const QVariantList &data);

private:
    QSqlDatabase db;

private:
    bool openDataBase();
    bool restoreDataBase();
    void closeDataBase();
    bool createWeatherTable();
};

#endif // DATABASE_H
