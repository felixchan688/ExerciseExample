#include "cxthreadexample.h"
#include <QThread>
#include <QDebug>
#include <QTimer>
#include <QEventLoop>
#include <QMutex>
#include <QMutexLocker>

Worker1::Worker1(QObject *parent): QObject(parent)
{

}

Worker1::~Worker1()
{
    qDebug() << "~Worker1";
}

void Worker1::run()
{
    int count = 0;
    while(count < 30)
    {
        qDebug() << QThread::currentThreadId();
        QThread::sleep(1);
        qDebug() << count++;
        if (QThread::currentThread()->isInterruptionRequested())
        {
            break;
        }
    }
    emit finish();
}



CxThreadExample::CxThreadExample(QObject *parent) : QObject(parent)
{
    timer = new QTimer;
}

void  CxThreadExample::test()
{
    qDebug() << "test";
}

CxThreadExample::~CxThreadExample()
{
    delete timer;
}

void  CxThreadExample::exampleTest()
{
    qDebug() << QThread::currentThreadId();
    Worker1 *w1 = new Worker1;
    QThread *t1 = new QThread;
    connect(t1, &QThread::started, w1, &Worker1::run);
    connect(w1, &Worker1::finish, t1, &QThread::quit);
    connect(w1, &Worker1::finish, w1, &Worker1::deleteLater);
    connect(t1, &QThread::finished, t1, &QThread::deleteLater);
    connect(timer, &QTimer::timeout, t1, &QThread::requestInterruption);

    w1->moveToThread(t1);
    t1->start();

    timer->start(3000);
    //t1->wait(3);
    QEventLoop loop;
    loop.exec();
}
