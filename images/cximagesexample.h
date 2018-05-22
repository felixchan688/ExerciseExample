#ifndef CXIMAGESEXAMPLE_H
#define CXIMAGESEXAMPLE_H

#include <QObject>

class CxImagesExample : public QObject
{
    Q_OBJECT
public:
    explicit CxImagesExample(QObject *parent = 0);
public:
    void   imageRead();

signals:

public slots:
};

#endif // CXIMAGESEXAMPLE_H
