#include "Database.h"

DataBase::DataBase(QObject *parent) : QObject(parent)
{

}

DataBase::~DataBase()
{

}

/* Методы для подключения к базе данных
 * */
void DataBase::connectToDataBase()
{
    /* Перед подключением к базе данных производим проверку на её существование.
     * В зависимости от результата производим открытие базы данных или её восстановление
     * */
    if(!QFile(DATABASE_NAME).exists()){
        this->restoreDataBase();
    } else {
        this->openDataBase();
    }
}

/* Методы восстановления базы данных
 * */
bool DataBase::restoreDataBase()
{
    if(this->openDataBase()){
        if(!this->createWeatherTable()){
            return false;
        } else {
            return true;
        }
    } else {
        qDebug() << "Не удалось восстановить базу данных";
        return false;
    }
    return false;
}

/* Метод для открытия базы данных
 * */
bool DataBase::openDataBase()
{
    /* База данных открывается по заданному пути
     * и имени базы данных, если она существует
     * */
    db = QSqlDatabase::addDatabase("QSQLITE");
    db.setHostName(DATABASE_HOSTNAME);
    db.setDatabaseName(DATABASE_NAME);
    if(db.open()){
        return true;
    } else {
        return false;
    }
}

/* Методы закрытия базы данных
 * */
void DataBase::closeDataBase()
{
    db.close();
}

/* Метод для создания таблицы устройств в базе данных
 * */
bool DataBase::createWeatherTable()
{
    /* В данном случае используется формирование сырого SQL-запроса
     * с последующим его выполнением.
     * */
    QSqlQuery query;
    if(!query.exec( "CREATE TABLE " WEATHER " ("
                            "id INTEGER PRIMARY KEY AUTOINCREMENT, "
                            WEATHER          " VARCHAR(255)    NOT NULL,"
                            WEATHER_DATE     " VARCHAR(10)     NOT NULL,"
                            WEATHER_TEMP     " VARCHAR(3)      NOT NULL,"
                            WEATHER_TEMPMIN  " VARCHAR(3)      NOT NULL,"
                            WEATHER_TEMPMAX  " VARCHAR(3)      NOT NULL,"
                            WEATHER_RAIN     " VARCHAR(20)     NOT NULL"
                        " )"
                    )){
        qDebug() << "DataBase: error of create " << WEATHER;
        qDebug() << query.lastError().text();
        return false;
    } else {
        return true;
    }
    return false;
}

/* Метод для вставки записи в таблицу устройств
 * */
bool DataBase::inserIntoDeviceTable(const QVariantList &data)
{
    //Запрос SQL
    QSqlQuery query;
    query.prepare("INSERT INTO " WEATHER " ( " WEATHER_DATE ", "
                                               WEATHER_TEMP ", "
                                               WEATHER_TEMPMIN ", "
                                               WEATHER_TEMPMAX ", "
                                               WEATHER_RAIN " ) "
                  "VALUES (:Date, :NormalTemp, :MinTemp, :MaxTemp, :WeatherRain )");

    query.bindValue(":Date",                data[0].toString());
    query.bindValue(":NormalTemp",          data[1].toString());
    query.bindValue(":MinTemp",             data[2].toString());
    query.bindValue(":MaxTemp",             data[3].toString());
    query.bindValue(":WeatherRain",         data[4].toString());

    if(!query.exec()){
        qDebug() << "error insert into " << WEATHER;
        qDebug() << query.lastError().text();
        return false;
    } else {
        return true;
    }
    return false;
}
