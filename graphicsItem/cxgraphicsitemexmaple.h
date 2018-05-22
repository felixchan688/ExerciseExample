#ifndef CXGRAPHICSITEMEXMAPLE_H
#define CXGRAPHICSITEMEXMAPLE_H

#include <QObject>

class CxGraphicsItemExmaple : public QObject
{
    Q_OBJECT
public:
    explicit CxGraphicsItemExmaple(QObject *parent = 0);
public:
    void  showSimpleTextItemExmaple();
    void  showTextItemExmaple();
    void  showLineItemExample();
    void  showPixmapItemExample();
    void  showRectItemExmaple();
    void  showOthersItemExmaple();
    void  showPathItemExample();
    void  showGraphicsWidgetExample();
    void  showGraphicsGroupExample();
    void  showCustomItemExample();
signals:


public slots:
};

#endif // CXGRAPHICSITEMEXMAPLE_H
