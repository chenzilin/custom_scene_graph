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
    Q_PROPERTY(QString tex READ tex WRITE setTex NOTIFY texChanged)

public:
    explicit Ring(QQuickItem *parent = 0);
    QSGNode *updatePaintNode(QSGNode *, UpdatePaintNodeData *);

    qreal ro() const { return mRo; }
    qreal ri() const { return mRi; }
    qreal startAngle() const { return mStartAngle; }
    qreal endAngle() const { return mEndAngle; }
    qreal angle() const { return mAngle; }
    int div() const { return mDiv; }
    QString tex() const { return mTex; }

    void setRo(qreal);
    void setRi(qreal);
    void setStartAngle(qreal);
    void setEndAngle(qreal);
    void setAngle(qreal);
    void setDiv(int);
    void setTex(const QString &);

signals:
    void roChanged(qreal);
    void riChanged(qreal);
    void startAngleChanged(qreal);
    void endAngleChanged(qreal);
    void angleChanged(qreal);
    void divChanged(int);
    void texChanged(const QString &);

private:
    qreal mRo;
    qreal mRi;
    qreal mStartAngle;
    qreal mEndAngle;
    qreal mAngle;
    int mDiv;
    QString mTex;
    bool mUpdateVertex;
    bool mUpdateTexture;
    bool mUpdateGeometry;
};

#endif // RING_H
