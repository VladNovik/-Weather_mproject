#ifndef WEATHERDATA_H
#define WEATHERDATA_H

#include <QWidget>
#include <QJsonDocument>
#include <QJsonObject>
#include <QJsonParseError>
#include <QtNetwork/QNetworkAccessManager>
#include <QtNetwork/QNetworkRequest>
#include <QtNetwork/QNetworkReply>
#include <QDebug>


class Weatherdata : public QObject
{
    Q_OBJECT

public:
    Weatherdata();
    ~Weatherdata();
    QJsonDocument doc;
    QJsonObject temp, temp1;
    QJsonObject city;
    QJsonValue cityName;
    QJsonParseError docEr;
    QNetworkAccessManager *network_manager;
    QNetworkRequest request;

private slots:
    void sendReq();
    void slot_network_manager(QNetworkReply*);
};


#endif // WEATHERDATA_H
