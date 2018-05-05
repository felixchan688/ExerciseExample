#ifndef CXTHREADEXAMPLE_H
#define CXTHREADEXAMPLE_H

#include <QObject>
#include <QThread>
//#include <>

class Worker1 : public QObject
{
    Q_OBJECT
public:
    explicit Worker1(QObject *parent = 0);
    ~Worker1();
public slots:
    void run();
signals:
    void finish();
};
class QTimer;
class CxThreadExample : public QObject
{
    Q_OBJECT
public:
    explicit CxThreadExample(QObject *parent = 0);
    ~CxThreadExample();
public:
    void  exampleTest();
signals:

public slots:
    void  test();
private:
    QTimer *timer;
};

/***************QWaitCondition --> producer & consumer *********/
#include <QWaitCondition>
#include <QMutex>
#include <QDebug>
#define MAX_BUF_SIZE 1024
static int usedBuffBytes   = 0;
static QWaitCondition buffNotEmpty;
static QWaitCondition buffNotFull;
static QMutex         mutex;

class ConditionProducer: public QThread
{
    Q_OBJECT
public:
    ConditionProducer(QObject *parent = NULL) : QThread(parent){}
public:
    void run() Q_DECL_OVERRIDE{
        while(1)
        {
        mutex.lock();
        if (usedBuffBytes == MAX_BUF_SIZE)
            buffNotFull.wait(&mutex);
        mutex.unlock();

        mutex.lock();
        usedBuffBytes++;
        qDebug("produce:%d", usedBuffBytes);
        buffNotEmpty.wakeAll();
        mutex.unlock();
        }
    }
};

class ConditionConsumer: public QThread
{
    Q_OBJECT
public:
    ConditionConsumer(QObject *parent = NULL) : QThread(parent){}
public:
    void run() Q_DECL_OVERRIDE{
        while(1)
        {
        mutex.lock();
        if (usedBuffBytes == 0)
            buffNotEmpty.wait(&mutex);
        mutex.unlock();

        mutex.lock();
        qDebug("consume:%d", usedBuffBytes);
        usedBuffBytes--;
        buffNotFull.wakeAll();
        mutex.unlock();
        }
    }
};



#endif // CXTHREADEXAMPLE_H
