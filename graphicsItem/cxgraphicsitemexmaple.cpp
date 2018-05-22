#include "cxgraphicsitemexmaple.h"
#include <QGraphicsItem>
#include <QGraphicsSimpleTextItem>
#include <QGraphicsScene>
#include <QGraphicsView>
#include <QFont>
#include <QBrush>
#include <QGraphicsTextItem>
#include <QGraphicsLineItem>
#include <QGraphicsPixmapItem>
#include <QGraphicsPolygonItem>
#include <QApplication>
#include <QIcon>
#include <QPixmap>
#include <QStyle>
#include <QGraphicsRectItem>
#include <QPainterPath>


CxGraphicsItemExmaple::CxGraphicsItemExmaple(QObject *parent) : QObject(parent)
{

}


void  CxGraphicsItemExmaple::showSimpleTextItemExmaple()
{
    QGraphicsSimpleTextItem *pItem = new QGraphicsSimpleTextItem();
    pItem->setText(QString::fromLocal8Bit("QGraphicsSimpleTextItem example"));

    QFont font = pItem->font();
    font.setPixelSize(20);
    font.setItalic(true);
    font.setUnderline(true);
    pItem->setFont(font);

    pItem->setBrush(QBrush(QColor(0, 160, 230)));

    QGraphicsScene *pScene = new QGraphicsScene();
    pScene->addItem(pItem);

    QGraphicsView *pView = new QGraphicsView();
    pView->setScene(pScene);
    pView->setStyleSheet("border:none; background:transparent;");
    pView->show();
}

void  CxGraphicsItemExmaple::showTextItemExmaple()
{
    QGraphicsTextItem *pItem = new QGraphicsTextItem();
    pItem->setPlainText(QString::fromLocal8Bit("QGraphicsTextItem example"));
    pItem->setDefaultTextColor(QColor(0, 160, 230));  // 文本色

    QString strHtml = QString("<html> \
                                <head>\
                                <style> font{color:white;} #f{font-size:18px; color: #00A0E6;} </style>\
                                </head> \
                                <body> \
                                <font>%1</font><font id=\"f\">%2</font> \
                                </body>\
                                </html>").arg("I am a ").arg("Qter");


    //pItem->setHtml(QString("<a href = \"%1\">%2</a>").arg("http://blog.csdn.net/liang19890820").arg(QStringLiteral("一去丶二三里")));
    //pItem->setOpenExternalLinks(true);
    //pItem->setOpenExternalLinkes(true);
    //pItem->setTextInteractionFlags(Qt::TextBrowserInteraction);
    //pItem->setTextInteractionFlags(Qt::TextBrowserInteraction);


   // pItem->setHtml(strHtml);
    QFont font = pItem->font();
    font.setPixelSize(20);
    font.setItalic(true);
    font.setUnderline(true);
    pItem->setFont(font);

    pItem->setTextInteractionFlags(Qt::TextEditorInteraction);

    QGraphicsScene *pScene = new QGraphicsScene();
    pScene->addItem(pItem);

    QGraphicsView *pView = new QGraphicsView();
    pView->setScene(pScene);
    pView->setStyleSheet("border:none; background:transparent;");
    pView->show();
}

void  CxGraphicsItemExmaple::showLineItemExample()
{
    QGraphicsLineItem *pItem = new QGraphicsLineItem();

    QPen pen = pItem->pen();
    pen.setColor(QColor(0, 160, 230));
    pen.setWidth(5);
    pItem->setPen(pen);

    pItem->setLine(QLineF(0,0, 100, 100));

    QGraphicsScene *pScene = new QGraphicsScene();
    pScene->addItem(pItem);

    // 为视图设置场景
    QGraphicsView *pView = new QGraphicsView();
    pView->setScene(pScene);
    pView->setStyleSheet("border:none; background:transparent;");

    pView->show();


}
void  CxGraphicsItemExmaple::showPixmapItemExample()
{
    QGraphicsPixmapItem *pItem = new QGraphicsPixmapItem();

    QStyle* style = QApplication::style();
    QIcon icon = style->standardIcon(QStyle::SP_DriveCDIcon);
    QPixmap pixmap = icon.pixmap(30, 30);
    pItem->setPixmap(pixmap.scaled(50, 50));

    // 将 item 添加至场景中
    QGraphicsScene *pScene = new QGraphicsScene();
    pScene->addItem(pItem);

    // 为视图设置场景
    QGraphicsView *pView = new QGraphicsView();
    pView->setScene(pScene);
    pView->setStyleSheet("border:none; background:transparent;");

    pView->show();
}

void  CxGraphicsItemExmaple::showRectItemExmaple()
{
    QGraphicsRectItem  *pItem = new QGraphicsRectItem();

    // 设置画笔、画刷
    QPen pen = pItem->pen();
    pen.setWidth(5);
    pen.setColor(Qt::white);
    pItem->setPen(pen);
    pItem->setBrush(QBrush(QColor(0, 160, 230)));

    // 矩形区域 起点：(50, 50) 宽：100 高：100
    pItem->setRect(QRectF(50, 50, 100, 100));

    // 将 item 添加至场景中
    QGraphicsScene *pScene = new QGraphicsScene();
    pScene->addItem(pItem);

    // 为视图设置场景
    QGraphicsView *pView = new QGraphicsView();
    pView->setScene(pScene);
    pView->setStyleSheet("border:none; background:transparent;");

    pView->show();
}

void  CxGraphicsItemExmaple::showOthersItemExmaple()
{
#if 0
    QGraphicsEllipseItem *pItem = new QGraphicsEllipseItem ();

    QPen pen = pItem->pen();
    pen.setWidth(5);
    pen.setColor(Qt::white);
    pItem->setPen(pen);
    pItem->setBrush(QBrush(QColor(0, 160, 230)));

    pItem->setRect(QRectF(50, 50, 200, 100));
    pItem->setStartAngle(16 * 90);
    pItem->setRect(QRectF(50,50,200, 200));
    pItem->setSpanAngle(16 * 270);
#else
    QGraphicsPathItem *pItem = new QGraphicsPathItem();
    QPainterPath path;
    path.addRect(50, 50, 50, 50);
    pItem->setPath(path);

    QPen pen = pItem->pen();
    pen.setWidth(2);
    pen.setColor(Qt::white);
    pItem->setPen(pen);
    pItem->setBrush(QBrush(QColor(0, 160, 230)));
    //pItem->setPath(pathItem);
#endif


    QGraphicsScene *pScene = new QGraphicsScene();
    pScene->addItem(pItem);

    QGraphicsView *pView = new QGraphicsView();
    pView->setScene(pScene);
    pView->setStyleSheet("border:none; background:transparent;");

    pView->show();
}

void  CxGraphicsItemExmaple::showPathItemExample()
{
    const float PI = 3.1415926f;
    QGraphicsPathItem *pItem = new QGraphicsPathItem();

    QPainterPath starPath;
    starPath.moveTo(90, 50);

    for (int i = 1; i < 5; i++)
    {
        starPath.lineTo(50 + 40*std::cos(0.8 * i * PI), 50 + 40 * std::sin(0.8 * i * PI));
    }
    starPath.closeSubpath();
    pItem->setPath(starPath);

    QPen pen = pItem->pen();
    pen.setWidth(2);
    pen.setColor(Qt::white);
    pItem->setPen(pen);
    pItem->setBrush(QBrush(QColor(0, 160, 230)));


    QGraphicsScene *pScene = new QGraphicsScene();
    pScene->addItem(pItem);

    QGraphicsView *pView = new QGraphicsView();
    pView->setScene(pScene);
    pView->setRenderHint(QPainter::Antialiasing);
    pView->setStyleSheet("border:none; background:transparent;");

    pView->show();

}
/*********************************************************/
/******* custom private smile graphics item **************/
/*********************************************************/
#include <QGraphicsItem>
class SmileItem : public QGraphicsItem
{
public:
    explicit SmileItem(QGraphicsItem *parent = Q_NULLPTR);
    explicit SmileItem(const QRect &rect, QGraphicsItem *parent = Q_NULLPTR);
    explicit SmileItem(qreal x, qreal y, qreal w, qreal h, QGraphicsItem *parent = Q_NULLPTR);
    ~SmileItem();

    QRectF rect() const;
    void   setRect(const QRectF &rect);
    //inline void setRect(qreal x, qreal y, qreal w, qreal h);

    QRectF boundingRect() const Q_DECL_OVERRIDE;
    void   paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget);

private:
    void   updateRect();
private:
    QRectF m_rect;
    mutable QRectF m_boundingRect;

    double  m_dScale;
    QPointF m_leftEyeCenter;
    QPointF m_rightEyeCenter;
    QPointF m_smileCenter;

    double m_dEyeWidth;
    double m_dEyeHeight;

    double m_dEyeBallWidth;

    double m_dSmileWidth;
    double m_dSmileHeight;
};

SmileItem::SmileItem(qreal x, qreal y, qreal w, qreal h, QGraphicsItem *parent) : QGraphicsItem(parent)
{
    setRect(QRect(x, y, w, h));
}

SmileItem::SmileItem(QGraphicsItem *parent): QGraphicsItem(parent)
{
    setRect(QRect(-50, -50, 100, 100));
}

SmileItem::~SmileItem()
{

}

QRectF SmileItem::rect() const
{
    return m_rect;
}

void SmileItem::setRect(const QRectF &rect)
{
    if (m_rect == rect)
        return;
    prepareGeometryChange();
    m_rect = rect;
    m_boundingRect = QRectF();
    updateRect();
    update();
}

QRectF SmileItem::boundingRect() const
{
    if (m_boundingRect.isNull())
    {
        m_boundingRect = m_rect;
    }
    return m_boundingRect;
}
void SmileItem::updateRect()
{
    m_dScale = m_rect.width()/100.00;
    m_leftEyeCenter.setX(-15 * m_dScale);
    m_leftEyeCenter.setY(-25 * m_dScale);

    m_rightEyeCenter.setX(15 * m_dScale);
    m_rightEyeCenter.setY(-25 * m_dScale);

    m_smileCenter.setX(0);
    m_smileCenter.setY(10 * m_dScale);

    m_dEyeWidth = m_rect.width() / (100.0/12);
    m_dEyeHeight = m_dEyeWidth * 2;

    m_dEyeBallWidth = m_dEyeWidth / 4;

    m_dSmileWidth = m_rect.width() / (100.0/66);
    m_dSmileHeight = m_rect.height() / (100.0 / 50);
}

void   SmileItem::paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget)
{
    Q_UNUSED(option);
    Q_UNUSED(option);

    painter->setRenderHint(QPainter::Antialiasing);

    painter->setPen(Qt::NoPen);
    painter->setBrush(Qt::yellow);
    painter->drawEllipse(m_rect);

    painter->setPen(QPen(Qt::black));
    painter->setBrush(Qt::white);


}
#include <QGroupBox>
#include <QLabel>
#include <QLineEdit>
#include <QFormLayout>

#pragma execution_character_set("utf-8")

void  CxGraphicsItemExmaple::showGraphicsWidgetExample()
{
    QGroupBox *pGroupBox = new QGroupBox();
    QLabel    *pTellLabel = new QLabel();
    QLabel    *pAddressLabel = new QLabel();
    QLineEdit *pTellLineEdit  = new QLineEdit();
    QLineEdit *pAddressLineEdit = new QLineEdit();

    pGroupBox->setTitle(QStringLiteral("联系方式"));
    pTellLabel->setText(QStringLiteral("电话号码"));
    pAddressLabel->setText(QStringLiteral("居住地址"));
    pTellLineEdit->setPlaceholderText(QStringLiteral("手机/固话"));
    pAddressLineEdit->setPlaceholderText(QStringLiteral("具体到门牌号"));

    QFormLayout *pLayout = new QFormLayout();
    pLayout->addRow(pTellLabel, pTellLineEdit);
    pLayout->addRow(pAddressLabel, pAddressLineEdit);

    pLayout->setSpacing(10);
    pLayout->setMargin(20);

    pGroupBox->setLayout(pLayout);

    QGraphicsScene *scene = new QGraphicsScene();
    QGraphicsProxyWidget *pProxy = scene->addWidget(pGroupBox);

    QGraphicsView *view = new QGraphicsView(scene);
    view->show();
}

#include <QGraphicsItemGroup>
void  CxGraphicsItemExmaple::showGraphicsGroupExample()
{
    QGraphicsItemGroup  *pGroup = new QGraphicsItemGroup();
    QGraphicsEllipseItem *pFrom = new QGraphicsEllipseItem();
    QGraphicsLineItem    *pLink = new QGraphicsLineItem();
    QGraphicsRectItem    *pTo   = new QGraphicsRectItem();

    pGroup->setFlags(QGraphicsItem::ItemIsSelectable | QGraphicsItem::ItemIsMovable);
    QPen pen = pFrom->pen();
    pen.setWidth(2);
    pen.setColor(QColor(0, 160, 230));
    pFrom->setPen(pen);
    pLink->setPen(pen);
    pTo->setPen(pen);
    pFrom->setBrush(QColor(247, 160, 57));
    pTo->setBrush(QColor(247, 160, 57));

    pGroup->addToGroup(pFrom);
    pGroup->addToGroup(pTo);
    pGroup->addToGroup(pLink);

    const double length = 50;
    pFrom->setRect(QRectF(-length/2.0, -length/2.0, length, length));
    pTo->setRect(QRectF(-length/2.0, length/2.0, length, length));

    pFrom->setPos(80, 80);
    pTo->setPos(200, 150);
    pLink->setLine(QLineF(pFrom->pos(), pTo->pos()));

    QGraphicsScene *pScene = new QGraphicsScene();
    pScene->setSceneRect(0, 0, 300, 200);
    pScene->addItem(pGroup);

    // 为视图设置场景
    QGraphicsView *pView = new QGraphicsView();
    pView->setRenderHint(QPainter::Antialiasing);
    pView->setScene(pScene);
    pView->show();
}
#include <QGraphicsSceneMouseEvent>
#include <QKeyEvent>
#include <QDebug>
class CustomItem : public QGraphicsRectItem
{
public:
    explicit CustomItem(QGraphicsItem *parent = 0);
protected:
    void  mousePressEvent(QGraphicsSceneMouseEvent *event);
    void  mouseMoveEvent(QGraphicsSceneMouseEvent *event);
    void  mouseReleaseEvent(QGraphicsSceneMouseEvent *event);
    int type() const;
private:
    QPointF m_centerPointF;
    bool    m_bResizing;
};

class CustomScene: public QGraphicsScene
{
protected:
    void mousePressEvent(QGraphicsSceneMouseEvent *event);
    void mouseMoveEvent(QGraphicsSceneMouseEvent *event);
    void keyPressEvent(QKeyEvent *event);
};
void CustomItem::mousePressEvent(QGraphicsSceneMouseEvent *event)
{
    if (event->button() == Qt::LeftButton)
    {
        if (event->modifiers() == Qt::ShiftModifier)
        {
            setSelected(true);
        }
        else if (event->modifiers() == Qt::AltModifier)
        {
            qDebug() << "custom left clicked with alt key";

            double radius = boundingRect().width() / 2.0;
            QPointF topLeft = boundingRect().topLeft();
            m_centerPointF  = QPointF(topLeft.x() + pos().x() + radius, topLeft.y() + pos().y() + radius);
            QPointF pos     = event->scenePos();
            qDebug() << boundingRect() << radius << this->pos() << pos << event->pos();
            double dist = sqrt(pow(m_centerPointF.x() - pos.x(), 2) + pow(m_centerPointF.y() - pos.y(), 2));
            if (dist / radius > 0.8)
            {
                qDebug() << dist << radius << dist / radius;
                m_bResizing = true;
            }
            else
            {
                m_bResizing = false;
            }
        }
        else
        {
            QGraphicsItem::mousePressEvent(event);
            event->accept();
        }
    }
    else if (event->button() == Qt::RightButton)
    {
        event->ignore();
    }
}

void CustomItem::mouseMoveEvent(QGraphicsSceneMouseEvent *event)
{
    if ((event->modifiers() == Qt::AltModifier) && m_bResizing)
    {
        QPointF pos  = event->scenePos();
        double dist  = sqrt(pow(m_centerPointF.x() - pos.x(), 2) + pow(m_centerPointF.y() - pos.y(), 2));

        setRect(m_centerPointF.x()-this->pos().x()-dist, m_centerPointF.y()-this->pos().y()-dist, dist*2, dist*2);
    }
    else if (event->modifiers() == Qt::AltModifier)
    {
        QGraphicsItem::mouseMoveEvent(event);
    }

}

void CustomItem::mouseReleaseEvent(QGraphicsSceneMouseEvent *event)
{
    if ((event->modifiers() == Qt::AltModifier) && m_bResizing)
    {
        m_bResizing = false;
    }
    else
    {
        QGraphicsItem::mouseReleaseEvent(event);
    }
}
int CustomItem::type() const
{
    return UserType + 1;
}

void CustomScene::mousePressEvent(QGraphicsSceneMouseEvent *event)
{
    QGraphicsScene::mousePressEvent(event);
    if (!event->isAccepted())
    {
        if (event->button() == Qt::LeftButton)
        {
            QPointF point = event->scenePos();
            CustomItem *item = new CustomItem();
            item->setRect(point.x() - 25, point.y() - 25, 60, 60);
            addItem(item);

        }
        else if (event->button() == Qt::RightButton)
        {
            QGraphicsItem *itemToRemove = NULL;
            foreach(QGraphicsItem *item, items(event->scenePos()))
            {
                if (item->type() == QGraphicsItem::UserType+1)
                {
                    itemToRemove = item;
                    break;
                }
            }
            if (itemToRemove != NULL)
            {
                removeItem(itemToRemove);
            }
        }

    }
}

void CustomScene::mouseMoveEvent(QGraphicsSceneMouseEvent *event)
{
    qDebug() << "Custom scene moved.";
    QGraphicsScene::mouseMoveEvent(event);
}
void CustomScene::keyPressEvent(QKeyEvent *event)
{
    if (event->key() == Qt::Key_Backspace)
    {
        while(!selectedItems().isEmpty())
        {
            removeItem(selectedItems().front());
        }
    }
    else
    {
        QGraphicsScene::keyPressEvent(event);
    }
}


CustomItem::CustomItem(QGraphicsItem *parent): QGraphicsRectItem(parent)
{
    QPen pen = this->pen();
    pen.setWidth(2);
    pen.setColor(QColor(0, 160, 230));
    setPen(pen);

    setBrush(QBrush(QColor(247, 160, 57)));
    setFlags(QGraphicsItem::ItemIsSelectable | QGraphicsItem::ItemIsMovable);
}

void  CxGraphicsItemExmaple::showCustomItemExample()
{
    CustomItem *pItem = new CustomItem();
    pItem->setRect(20, 20, 60, 60);

    // 将 item 添加至场景中
    CustomScene *scene  = new CustomScene;
    scene->setSceneRect(0, 0, 400, 300);
    scene->addItem(pItem);

    // 为视图设置场景
    QGraphicsView *view = new QGraphicsView;
    view->setScene(scene);
    view->show();
}
