#include <QPropertyAnimation>
#include "cxanimationexample.h"
#include <QLabel>
#include <QPushButton>
#include <QSequentialAnimationGroup>
#include <QParallelAnimationGroup>
#include <QPauseAnimation>

CxAnimationExample::CxAnimationExample(QWidget *parent) : QDialog(parent)
{
    setMinimumSize(400, 400);
}

void CxAnimationExample::showMoveExample()
{
    QLabel *m_pLabel  = new QLabel(this);
    m_pLabel->setText("one two there!");
    m_pLabel->setScaledContents(true);
    QPushButton *pStartButton =  new QPushButton( "start animation", this);
    pStartButton->setGeometry(100, 50, 200, 30);
    QPropertyAnimation *pAnimation = new QPropertyAnimation(m_pLabel, "geometry");
    pAnimation->setDuration(1000);
    pAnimation->setStartValue(QRect(0, 0, 200, 25));
    pAnimation->setEndValue(QRect(200, 130, 200, 25));
    pAnimation->setEasingCurve(QEasingCurve::InSine); //OutBounce InQuad

    connect(pStartButton, SIGNAL(clicked(bool)), pAnimation, SLOT(start()));
    this->exec();
}

int  CxAnimationExample::alpha() const
{
    return this->m_nAlpha;
}

void CxAnimationExample::setAlpha(const int alpha)
{
    m_nAlpha = alpha;
    QString strQSS = QString("color: rgb(0, 160, 230); background-color: rgba(10, 160, 105, %1);").arg(m_nAlpha);
    m_pLabel->setStyleSheet(strQSS);
}

void CxAnimationExample::showAlphaExample()
{
    m_pLabel  = new QLabel(this);
    m_pLabel->setText("one two there!");
    m_pLabel->setScaledContents(true);
    QPushButton *pStartButton =  new QPushButton( "start animation", this);
    pStartButton->setGeometry(100, 50, 200, 30);
    m_pLabel->setStyleSheet("color: rgb(0, 160, 230);");

    QPropertyAnimation *pAnimation = new QPropertyAnimation();
    pAnimation->setTargetObject(this);
    pAnimation->setPropertyName("alpha");
    pAnimation->setDuration(1000);
    pAnimation->setKeyValueAt(0, 255);
    pAnimation->setKeyValueAt(0.5, 100);
    pAnimation->setKeyValueAt(1, 255);
    pAnimation->setLoopCount(-1);

    connect(pStartButton, SIGNAL(clicked(bool)), pAnimation, SLOT(start()));
    this->exec();

}

void CxAnimationExample::showSequentialGroupExample()
{
    QLabel *m_pLabel1  = new QLabel(this);
    m_pLabel1->setText("one two there!");
    m_pLabel1->setScaledContents(true);
    m_pLabel1->setGeometry(QRect(0, 0, 200, 25));

    QLabel *m_pLabel2  = new QLabel(this);
    m_pLabel2->setText("one two there!");
    m_pLabel2->setScaledContents(true);
    m_pLabel2->setGeometry(QRect(200, 0, 200, 25));


    QPushButton *pStartButton =  new QPushButton( "start animation", this);
    pStartButton->setGeometry(100, 50, 200, 30);

    QPropertyAnimation *pAnimation1 = new QPropertyAnimation(m_pLabel1, "geometry");
    pAnimation1->setDuration(1000);
    pAnimation1->setStartValue(QRect(0, 0, 200, 25));
    pAnimation1->setEndValue(QRect(100, 130, 200, 25));
    pAnimation1->setEasingCurve(QEasingCurve::OutBounce);

    QPropertyAnimation *pAnimation2 = new QPropertyAnimation(m_pLabel2, "geometry");
    pAnimation2->setDuration(1000);
    pAnimation2->setStartValue(QRect(200, 0, 200, 25));
    pAnimation2->setEndValue(QRect(100, 200, 200, 25));
    pAnimation2->setEasingCurve(QEasingCurve::OutBounce);

#if 1
    QSequentialAnimationGroup *m_pGroup = new QSequentialAnimationGroup(this);

    m_pGroup->addAnimation(pAnimation1);
    //m_pGroup->addPause(1000);
    QPauseAnimation *pPauseAnimatin = new QPauseAnimation(this);
    pPauseAnimatin->setDuration(1000);
    m_pGroup->addAnimation(pPauseAnimatin);
    m_pGroup->addAnimation(pAnimation2);
    m_pGroup->setLoopCount(2);

    m_pGroup->setDirection(QAbstractAnimation::Backward);
#else
    QParallelAnimationGroup *m_pGroup = new QParallelAnimationGroup(this);
    m_pGroup->addAnimation(pAnimation1);
    m_pGroup->addAnimation(pAnimation2);
#endif
    connect(pStartButton, SIGNAL(clicked(bool)), m_pGroup, SLOT(start()));

    //connect(pStartButton, SIGNAL(clicked(bool)), pAnimation, SLOT(start()));
    this->exec();
}
#include <QProgressBar>
#include <QTimeLine>
void CxAnimationExample::showTimeLineExmaple()
{
    QProgressBar *progressBar = new QProgressBar(this);
    progressBar->setRange(0, 100);
    progressBar->setGeometry(0, 200, 400, 30);
    QTimeLine *timeLine = new QTimeLine(1000, this);
    timeLine->setFrameRange(0, 100);
    connect(timeLine, SIGNAL(frameChanged(int)), progressBar, SLOT(setValue(int)));


    QPushButton *pStartButton =  new QPushButton( "start animation", this);
    pStartButton->setGeometry(100, 50, 200, 30);
    connect(pStartButton, SIGNAL(clicked(bool)), timeLine, SLOT(start()));
    this->exec();
}
#include <QVBoxLayout>
#include <QDesktopWidget>
#include <QApplication>


void CxAnimationExample::onDropWindow()
{
    QPropertyAnimation *pAnimaton = new QPropertyAnimation(this, "geometry");

    QDesktopWidget     *pDesktopWidget = QApplication::desktop();
    int x = (pDesktopWidget->availableGeometry().width() - width())/2;
    int y = (pDesktopWidget->availableGeometry().height() - height())/2;

    pAnimaton->setDuration(1000);
    pAnimaton->setStartValue(QRect(x, 0, width(), height()));
    pAnimaton->setEndValue(QRect(x, y, width(), height()));
    pAnimaton->setEasingCurve(QEasingCurve::OutElastic);
    pAnimaton->start(QAbstractAnimation::DeleteWhenStopped);
}

void CxAnimationExample::onShakeWindow()
{
    QPropertyAnimation *pAnimation = new QPropertyAnimation(this, "pos");
    QPoint point = this->pos();
    pAnimation->setDuration(500);
    pAnimation->setLoopCount(2);
    pAnimation->setKeyValueAt(0, point - QPoint(-3, -3));
    pAnimation->setKeyValueAt(0.1, point - QPoint(6, 6));
    pAnimation->setKeyValueAt(0.2, point - QPoint(-6, -6));
    pAnimation->setKeyValueAt(0.3, point - QPoint(6, 6));
    pAnimation->setKeyValueAt(0.4, point - QPoint(-6, -6));
    pAnimation->setKeyValueAt(0.5, point - QPoint(6, 6));
    pAnimation->setKeyValueAt(0.6, point - QPoint(-6, -6));
    pAnimation->setKeyValueAt(0.7, point - QPoint(6, 6));
    pAnimation->setKeyValueAt(0.8, point - QPoint(-6, -6));
    pAnimation->setKeyValueAt(0.9, point - QPoint(6, 6));
    pAnimation->setKeyValueAt(1, point - QPoint(-3, -3));
    pAnimation->start(QAbstractAnimation::DeleteWhenStopped);
}

void CxAnimationExample::onOpacityWindow()
{
    QPropertyAnimation *pAnimation = new QPropertyAnimation(this, "windowOpacity");
    pAnimation->setDuration(1000);
    pAnimation->setKeyValueAt(0, 1);
    pAnimation->setKeyValueAt(0.5, 0);
    pAnimation->setKeyValueAt(1, 1);
    pAnimation->start(QAbstractAnimation::DeleteWhenStopped);
}

void CxAnimationExample::showMultiAnimationExamles()
{
    QPushButton *pButton = 0;
    QVBoxLayout *layout = new QVBoxLayout(this);
    pButton =  new QPushButton( "drop window");
    connect(pButton, SIGNAL(clicked(bool)), this, SLOT(onDropWindow()));
    layout->addWidget(pButton);
    pButton =  new QPushButton( "shake window");
    connect(pButton, SIGNAL(clicked(bool)), this, SLOT(onShakeWindow()));
    layout->addWidget(pButton);
    pButton =  new QPushButton( "opacity window");
    connect(pButton, SIGNAL(clicked(bool)), this, SLOT(onOpacityWindow()));
    layout->addWidget(pButton);
    this->setLayout(layout);
    this->exec();
}
