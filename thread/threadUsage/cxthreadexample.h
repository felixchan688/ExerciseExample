#ifndef CXTHREADEXAMPLE_H
#define CXTHREADEXAMPLE_H

#include <QObject>
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

#endif // CXTHREADEXAMPLE_H
