#include "networkexercisewin.h"
#include <QDebug>
#include <QHostInfo>
#include <QNetworkInterface>
#include <QUrl>
#include <QUrlQuery>

static bool isLinkLocalAddress(const QHostAddress &addr){
    quint32 nIPv4 = addr.toIPv4Address();
    quint32 nMinRange = QHostAddress("169.254.1.0").toIPv4Address();
    quint32 nMaxRange = QHostAddress("169.254.254.255").toIPv4Address();
    if ((nIPv4 >= nMinRange) && (nIPv4 <= nMaxRange)) {
        return true;
    } else {
        return false;
    }
}

static bool isLocalIP(const QHostAddress &addr){
    quint32 nIPv4 = addr.toIPv4Address();
    quint32 nMinRange1 = QHostAddress("10.0.0.0").toIPv4Address();
    quint32 nMaxRange1 = QHostAddress("10.255.255.255").toIPv4Address();

    quint32 nMinRange2 = QHostAddress("172.16.0.0").toIPv4Address();
    quint32 nMaxRange2 = QHostAddress("172.31.255.255").toIPv4Address();

    quint32 nMinRange3 = QHostAddress("192.168.0.0").toIPv4Address();
    quint32 nMaxRange3 = QHostAddress("192.168.255.255").toIPv4Address();

    if ((nIPv4 >= nMinRange1 && nIPv4 <= nMaxRange1)
            || (nIPv4 >= nMinRange2 && nIPv4 <= nMaxRange2)
            || (nIPv4 >= nMinRange3 && nIPv4 <= nMaxRange3)) {
        return true;
    } else {
        return false;
    }
}

NetworkExerciseWin::NetworkExerciseWin(QWidget *parent) : QMainWindow(parent)
{
    //printHostInfo();
    //printHostAddresses();
    //printAllInterface();
    testQuery();
}

void NetworkExerciseWin::lookedUp(const QHostInfo &host)
{
    if (host.error() != QHostInfo::NoError)
    {
        qDebug() << "lookup failed:" << host.errorString();
        return;
    }

    foreach(const QHostAddress &address, host.addresses())
    {
        if (address.protocol() == QAbstractSocket::IPv4Protocol)
        {
            qDebug() << "Found IPv4 address:" << address.toString();
        }
        else if (address.protocol() == QAbstractSocket::IPv6Protocol)
        {
            qDebug() << "Found IPv6 address:" << address.toString();
        }
        else
        {
            qDebug() << "Other address:" << address.toString();
        }
    }

    qDebug() << "Found host name:" << host.hostName();
}

void NetworkExerciseWin::printHostInfo()
{
    QString localHostName  = QHostInfo::localHostName();
    QString localDemainName = QHostInfo::localDomainName();
    qDebug() << "Host name:" << localHostName;
    qDebug() << "DNS demain:" << localDemainName;
    qDebug() << "|************************************|";

    QHostInfo::lookupHost("qt-project.org", this, SLOT( lookedUp(QHostInfo) ) );
    QHostInfo::lookupHost("5.254.113.102", this, SLOT( lookedUp(QHostInfo) ) );

    QHostInfo  host = QHostInfo::fromName("5.254.113.102");
    if (host.error() != QHostInfo::NoError)
    {
        qDebug() << "lookup failed:" << host.errorString();
    }
    else
    {
        qDebug() << "Found hostName:" << host.hostName();
    }
}

void NetworkExerciseWin::printHostAddresses()
{
    QList<QHostAddress> list = QNetworkInterface::allAddresses();
    foreach(QHostAddress address, list)
    {
        if (address.isNull())
        {
            continue;
        }
        //if (isLinkLocalAddress(address) || isLocalIP(address))  continue;
        qDebug() << "********************";
        QAbstractSocket::NetworkLayerProtocol nProtocol = address.protocol();
        QString strScopeId = address.scopeId();
        QString strAddress = address.toString();
        QString bLoopback  = address.isLoopback();

        if (nProtocol == QAbstractSocket::IPv4Protocol)
        {
            bool bOk  = false;
            quint32 nIPV4 = address.toIPv4Address(&bOk);
            if (bOk)
                qDebug() << "IPV4:" << nIPV4;
        }
        else if (nProtocol == QAbstractSocket::IPv6Protocol)
        {
            QStringList IPV6List("");
            Q_IPV6ADDR IPV6 = address.toIPv6Address();
            for (int i = 0; i < 16; i++)
            {
                quint8 nc = IPV6[i];
                IPV6List << QString::number(nc);
            }
            qDebug() << "IPV6 : " << IPV6List.join(" ");
        }

        qDebug() << "Protocol : " << nProtocol;
        qDebug() << "ScopeId : " << strScopeId;
        qDebug() << "Address : " << strAddress;
        qDebug() << "IsLoopback  : " << bLoopback;
    }
}

void NetworkExerciseWin::printAllInterface()
{
    QList<QNetworkInterface> list = QNetworkInterface::allInterfaces();

    foreach (QNetworkInterface var, list) {
        if (!var.isValid()) continue;

        qDebug() << "***************";

        QNetworkInterface::InterfaceFlags flags = var.flags();
        if (flags.testFlag(QNetworkInterface::IsRunning)
            && !flags.testFlag(QNetworkInterface::IsLoopBack))

            qDebug() << "Device:" << var.name();
            qDebug() << "HardwareAddress:" << var.hardwareAddress();
            qDebug() << "Human Readable Name:" << var.humanReadableName();
    }
}

void NetworkExerciseWin::testQuery()
{
    QString baseUrl = "http://www.zhihu.com/search";
    QUrl url(baseUrl);

    QUrlQuery query;
    query.addQueryItem("type", "content");
    query.addQueryItem("q", "Qt");

    url.setQuery(query);

    qDebug() << url;
    qDebug() << query.queryPairDelimiter();
    qDebug() << query.queryValueDelimiter();

    query.setQueryDelimiters('$',';');
    url.setQuery(query);
    qDebug() << "*******************************************";
    qDebug() << url;
    qDebug() << query.queryPairDelimiter();
    qDebug() << query.queryValueDelimiter();

    qDebug() << query.hasQueryItem("q") << query.queryItemValue("q");
    query.removeQueryItem("q");
    qDebug() << query.hasQueryItem("q");
}

