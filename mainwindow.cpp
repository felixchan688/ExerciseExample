#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "Exercise/networkexercisewin.h"
#include "threadUsage/cxthreadexample.h"
#include "cxjsonexample.h"
#include "cximagesexample.h"
#include "cxgraphicsitemexmaple.h"
#include "cxgraphicsviewexmple.h"
#include "cxanimationexample.h"

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

    btn = new QPushButton(this);
    btn->setText(tr("json"));
    btn->setObjectName(QString("json"));
    connect(btn, SIGNAL(clicked(bool)), this, SLOT(showExample()));
    layout->addWidget(btn, 1, 0, 1, 1);

    btn = new QPushButton(this);
    btn->setText(tr("createImage"));
    btn->setObjectName(QString("createImage"));
    connect(btn, SIGNAL(clicked(bool)), this, SLOT(showExample()));
    layout->addWidget(btn, 1, 1, 1, 1);

    btn = new QPushButton(this);
    btn->setText(tr("graphicsItem"));
    btn->setObjectName(QString("graphicsItem"));
    connect(btn, SIGNAL(clicked(bool)), this, SLOT(showExample()));
    layout->addWidget(btn, 2, 0, 1, 1);

    btn = new QPushButton(this);
    btn->setText(tr("graphicsView"));
    btn->setObjectName(QString("graphicsView"));
    connect(btn, SIGNAL(clicked(bool)), this, SLOT(showExample()));
    layout->addWidget(btn, 2, 1, 1, 1);

    btn = new QPushButton(this);
    btn->setText(tr("animation"));
    btn->setObjectName(QString("animation"));
    connect(btn, SIGNAL(clicked(bool)), this, SLOT(showExample()));
    layout->addWidget(btn, 3, 0, 1, 1);

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
    else if (objName == QString("json"))
    {
        CxJsonExample jsonExample;
        jsonExample.jsonCreationExample();
    }
    else if (objName == QString("createImage"))
    {
        CxImagesExample createImage;
        createImage.imageRead();
    }
    else if (objName == QString("graphicsItem"))
    {
        CxGraphicsItemExmaple itemExample;
        itemExample.showCustomItemExample(); //showRectItemExmaple showOthersItemExmaple
    }
    else if (objName == QString("graphicsView"))
    {
        CxGraphicsViewExmple  viewExample;
        viewExample.showCustomGraphicsViewExample();
    }
    else if (objName == QString("animation"))
    {
        CxAnimationExample example;
        //showTimeLineExmaple  showSequentialGroupExample showMultiAnimationExamles
        example.showMultiAnimationExamles(); //showAlphaExample  showMoveExample showSequentialGroupExample
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
