#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "Network/Exercise/networkexercisewin.h"
#include "thread/threadUsage/cxthreadexample.h"

#include <QPushButton>
#include <QGridLayout>
#include <QDebug>
#include <QWidget>

CenterWidget::CenterWidget(QWidget *parent): QWidget(parent)
{
    QPushButton *btn = 0;

    QGridLayout *layout = new QGridLayout(this);

    btn = new QPushButton(this);
    btn->setText(tr("network"));
    btn->setObjectName(QString("network"));
    connect(btn, SIGNAL(clicked(bool)), this, SLOT(showExample()));
    layout->addWidget(btn, 0, 0, 1, 1);

    btn = new QPushButton(this);
    btn->setText(tr("thread"));
    btn->setObjectName(QString("thread"));
    connect(btn, SIGNAL(clicked(bool)), this, SLOT(showExample()));
    layout->addWidget(btn, 0, 1, 1, 1);
    this->setLayout(layout);
}

void CenterWidget::showExample()
{
    QString objName = sender()->objectName();
    if (objName == QString("network"))
    {
        NetworkExerciseWin *win = new NetworkExerciseWin(this);
        win->show();
    }
    else if (objName == QString("thread"))
    {
        CxThreadExample exmaple;
        exmaple.exampleTest();
    }
}

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    CenterWidget *centerWidget = new CenterWidget(this);
    this->setCentralWidget(centerWidget);
}

MainWindow::~MainWindow()
{
    delete ui;
}
