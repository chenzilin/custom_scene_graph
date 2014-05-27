#ifndef RING_H
#define RING_H

#include <QQuickItem>

class Ring : public QQuickItem
{
    Q_OBJECT

    Q_PROPERTY(qreal ro READ ro WRITE setRo NOTIFY roChanged)
    Q_PROPERTY(qreal ri READ ri WRITE setRi NOTIFY riChanged)
    Q_PROPERTY(qreal startAngle READ startAngle WRITE setStartAngle NOTIFY startAngleChanged)
    Q_PROPERTY(qreal endAngle READ endAngle WRITE setEndAngle NOTIFY endAngleChanged)
    Q_PROPERTY(qreal angle READ angle WRITE setAngle NOTIFY angleChanged)
    Q_PROPERTY(int div READ div WRITE setDiv NOTIFY divChanged)
    Q_PROPERTY(QString src1 READ src1 WRITE setSrc1 NOTIFY src1Changed)
    Q_PROPERTY(QString src2 READ src2 WRITE setSrc2 NOTIFY src2Changed)

public:
    explicit Ring(QQuickItem *parent = 0);
    QSGNode *updatePaintNode(QSGNode *, UpdatePaintNodeData *);

    qreal ro() const { return mRo; }
    qreal ri() const { return mRi; }
    qreal startAngle() const { return mStartAngle; }
    qreal endAngle() const { return mEndAngle; }
    qreal angle() const { return mAngle; }
    int div() const { return mDiv; }
    QString src1() const { return mSrc1; }
    QString src2() const { return mSrc2; }

    void setRo(qreal);
    void setRi(qreal);
    void setStartAngle(qreal);
    void setEndAngle(qreal);
    void setAngle(qreal);
    void setDiv(int);
    void setSrc1(const QString &);
    void setSrc2(const QString &);

signals:
    void roChanged(qreal);
    void riChanged(qreal);
    void startAngleChanged(qreal);
    void endAngleChanged(qreal);
    void angleChanged(qreal);
    void divChanged(int);
    void src1Changed(const QString &);
    void src2Changed(const QString &);

private:
    qreal mRo;
    qreal mRi;
    qreal mStartAngle;
    qreal mEndAngle;
    qreal mAngle;
    int mDiv;
    QString mSrc1;
    QString mSrc2;
};

#endif // RING_H
