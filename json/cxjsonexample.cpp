
#include "cxjsonexample.h"
#include <QJsonDocument>
#include <QJsonArray>
#include <QJsonObject>
#include <QDebug>

CxJsonExample::CxJsonExample(QObject *parent) : QObject(parent)
{

}


void  CxJsonExample::jsonCreationExample()
{
    //create QJsonArray
    QJsonArray jsonArray;
    jsonArray.append(4.8);
    jsonArray.append(5.2);
    jsonArray.append(5.7);

    QJsonObject jsonObject;
    jsonObject.insert("Home", "https://www.qt.io/");
    jsonObject.insert("Download", "https://www.qt.io/download/");
    jsonObject.insert("Developers", "https://www.qt.io/developers/");

    QJsonObject json;
    json.insert("Name", "Qt");
    json.insert("Company", "Digia");
    json.insert("From", 1991);
    json.insert("Version", jsonObject);
    json.insert("Page", jsonArray);

    QJsonDocument jsonDocument;
    jsonDocument.setObject(json);

    QByteArray byteArray = jsonDocument.toJson(QJsonDocument::Compact);

    QString strJon(byteArray);
    qDebug() << strJon;

}

