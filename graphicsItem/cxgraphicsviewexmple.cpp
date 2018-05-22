#include "cxgraphicsviewexmple.h"
#include <qgraphicsview.h>
#include <QGraphicsScene>
#include <QMouseEvent>
#include <QGraphicsRectItem>
#include <QDebug>
#include <QWheelEvent>
class CxCustomGraphicsView: public QGraphicsView
{
public:
    explicit CxCustomGraphicsView(QWidget *parent = Q_NULLPTR);
public:
     void translate(QPointF delta);
     void zoomIn();
     void zoomOut();
     void zoom(qreal scaleFactor);
protected:
    void mousePressEvent(QMouseEvent *event) Q_DECL_OVERRIDE;
    void mouseReleaseEvent(QMouseEvent *event) Q_DECL_OVERRIDE;
    void mouseMoveEvent(QMouseEvent *event) Q_DECL_OVERRIDE;
    void wheelEvent(QWheelEvent *event) Q_DECL_OVERRIDE;

private:
    qreal  m_translateStep;
    qreal  m_scaleFactor;
    bool   m_mouseTranslate;
    QPoint m_lastMousePos;
};
#define VIEW_CENTER viewport()->rect().center()
#define VIEW_WIDTH  viewport()->rect().width()
#define VIEW_HEIGHT viewport()->rect().height()

CxCustomGraphicsView::CxCustomGraphicsView(QWidget *parent):QGraphicsView(parent)
{
    m_translateStep = 1.0;
    m_scaleFactor   = 0.2;
    m_mouseTranslate = false;
    this->setTransformationAnchor(QGraphicsView::NoAnchor);
    this->setResizeAnchor(QGraphicsView::NoAnchor);
}

void CxCustomGraphicsView::mousePressEvent(QMouseEvent *event)
{
    if (event->button() == Qt::LeftButton)
    {
        QPointF point = mapToScene(event->pos());
        if (scene()->itemAt(point, transform()) == NULL)
        {
            m_mouseTranslate = true;
            m_lastMousePos   = event->pos();
            qDebug("press mouse");
        }
    }
    QGraphicsView::mousePressEvent(event);
}

void CxCustomGraphicsView::mouseMoveEvent(QMouseEvent *event)
{
    if (m_mouseTranslate)
    {
        QPointF mouseDelta = mapToScene(event->pos()) - mapToScene(m_lastMousePos);
        qDebug() << "mouse mvoe" << mouseDelta;
        translate(mouseDelta);
    }
    m_lastMousePos = event->pos();
    QGraphicsView::mouseMoveEvent(event);

}

void CxCustomGraphicsView::mouseReleaseEvent(QMouseEvent *event)
{
    if (event->button() == Qt::LeftButton && m_mouseTranslate)
    {
        m_mouseTranslate = false;
    }
    QGraphicsView::mouseReleaseEvent(event);
}

void CxCustomGraphicsView::translate(QPointF delta)
{
#if 1
    delta *= m_translateStep;
    QGraphicsView::translate(delta.x(), delta.y());
#else
    setTransformationAnchor(QGraphicsView::AnchorUnderMouse);
    QPoint newCenter(VIEW_WIDTH / 2 - delta.x(),  VIEW_HEIGHT / 2 - delta.y());
    centerOn(mapToScene(newCenter));
    setTransformationAnchor(QGraphicsView::AnchorViewCenter);
#endif
}
#include <QWheelEvent>
void CxCustomGraphicsView::wheelEvent(QWheelEvent *event)
{
    QPoint scrollCount = event->angleDelta();
    scrollCount.y() > 0? zoomIn() : zoomOut();
}

void CxCustomGraphicsView::zoomIn()
{
    zoom(1 + m_scaleFactor);
}

void CxCustomGraphicsView::zoomOut()
{
    zoom(1 - m_scaleFactor);
}

void CxCustomGraphicsView::zoom(qreal scaleFactor)
{
    qreal factor = transform().scale(scaleFactor, scaleFactor).mapRect(QRectF(0, 0, 1, 1)).width();
    if (factor < 0.07 || factor > 100)
    {
        return;
    }
    scale(scaleFactor, scaleFactor);
    m_scaleFactor *=  scaleFactor;
}

CxGraphicsViewExmple::CxGraphicsViewExmple(QObject *parent) : QObject(parent)
{

}

void     CxGraphicsViewExmple::showCustomGraphicsViewExample()
{
    QGraphicsRectItem *item = new QGraphicsRectItem();
    QPen pen = item->pen();
    pen.setWidth(3);
    pen.setColor(QColor(0, 0, 220));
    item->setPen(pen);
    item->setBrush(QColor(255, 0, 0));
    item->setRect(200, 200, 100, 100);

    QGraphicsScene *scene = new QGraphicsScene();
    scene->setSceneRect(0, 0, 1000, 1000);
    scene->addItem(item);

    CxCustomGraphicsView *view = new CxCustomGraphicsView;
    view->setScene(scene);
    view->show();
}
