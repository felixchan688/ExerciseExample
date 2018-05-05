#ifndef NETWORKEXERCISEWIN_H
#define NETWORKEXERCISEWIN_H

#include <QMainWindow>
#include <QHostInfo>

class NetworkExerciseWin : public QMainWindow
{
    Q_OBJECT
public:
    explicit NetworkExerciseWin(QWidget *parent = 0);
public:
    void printHostInfo();
    void printHostAddresses();
    void printAllInterface();
    void testQuery();

signals:

public slots:
    void lookedUp(const QHostInfo &host);
};

#endif // NETWORKEXERCISEWIN_H
