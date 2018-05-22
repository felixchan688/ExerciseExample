#ifndef CXGRAPHICSVIEWEXMPLE_H
#define CXGRAPHICSVIEWEXMPLE_H

#include <QObject>

class CxGraphicsViewExmple : public QObject
{
    Q_OBJECT
public:
    explicit CxGraphicsViewExmple(QObject *parent = 0);
public:
    void     showCustomGraphicsViewExample();

signals:

public slots:
};

#endif // CXGRAPHICSVIEWEXMPLE_H
