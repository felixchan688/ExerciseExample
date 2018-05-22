#ifndef CXANIMATIONEXAMPLE_H
#define CXANIMATIONEXAMPLE_H

#include <QDialog>
class QLabel;
class CxAnimationExample : public QDialog
{
    Q_OBJECT
    Q_PROPERTY(int alpha READ alpha WRITE setAlpha)
public:
    explicit CxAnimationExample(QWidget *parent = 0);
public:
    void showMoveExample();
    void showAlphaExample();
    void showSequentialGroupExample();
    void showTimeLineExmaple();
    void showMultiAnimationExamles();
private slots:
    void onDropWindow();
    void onShakeWindow();
    void onOpacityWindow();
signals:

public slots:
private:
    int  alpha() const;
    void setAlpha(const int alpha);
private:
    int    m_nAlpha;
    QLabel *m_pLabel;
};

#endif // CXANIMATIONEXAMPLE_H
