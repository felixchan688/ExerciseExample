#ifndef CXJSONEXAMPLE_H
#define CXJSONEXAMPLE_H

#include <QObject>

class CxJsonExample : public QObject
{
    Q_OBJECT
public:
    explicit CxJsonExample(QObject *parent = 0);

public:
    void  jsonCreationExample();

signals:

public slots:
};

#endif // CXJSONEXAMPLE_H
