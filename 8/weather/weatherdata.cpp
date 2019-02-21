#include "weatherdata.h"
#include "weather.h"
#include <QString>
#include <QVector>
#include <cstring>

Weatherdata::Weatherdata()
{
    network_manager = new QNetworkAccessManager(this);
    connect(network_manager,SIGNAL(finished(QNetworkReply*)),this,SLOT(slot_network_manager(QNetworkReply*)));

    QString apiCall = "Minsk";
    QUrl url("http://api.openweathermap.org/data/2.5/weather?q=" + apiCall + "&APPID=bae76904bfbaeb5a02be9c320a7b9b8b");
    request.setUrl(QUrl(url));
    sendReq();
}

Weatherdata::~Weatherdata()
{
    delete network_manager;
}

void Weatherdata::sendReq()
{
    network_manager->get(request);
}

void Weatherdata::slot_network_manager(QNetworkReply *rep)
{

    doc = QJsonDocument::fromJson(rep->readAll(),&docEr);

    QString editDoc(doc.toJson(QJsonDocument::Compact));

    qDebug()<<editDoc;

    if(docEr.errorString().toInt() == QJsonParseError::NoError)
    {
       temp = doc.object().value("main").toObject();
       qDebug()<<"temp: "<<temp.value("temp").toDouble()-273.13;
       city = doc.object();
       connect(slot_network_manager())
       qDebug()<<"temp: "<<city.value("name").toString();


       //weatherdata::string = city.value("name").toString();

    }

    QFile file("out.txt");
    if (!file.open(QIODevice::WriteOnly | QIODevice::Text))
             return;

    QTextStream out(&file);
    out << editDoc;
    file.close();
}
