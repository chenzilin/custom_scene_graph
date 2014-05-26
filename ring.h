#ifndef RING_H
#define RING_H

#include <QQuickItem>

class Ring : public QQuickItem
{
    Q_OBJECT

    Q_PROPERTY(qreal ro READ ro WRITE setRo NOTIFY roChanged)
    Q_PROPERTY(qreal ri READ ri WRITE setRi NOTIFY riChanged)
    Q_PROPERTY(qreal angle READ angle WRITE setAngle NOTIFY angleChanged)
    Q_PROPERTY(int div READ div WRITE setDiv NOTIFY divChanged)

public:
    explicit Ring(QQuickItem *parent = 0);
    QSGNode *updatePaintNode(QSGNode *, UpdatePaintNodeData *);

    qreal ro() const { return mRo; }
    qreal ri() const { return mRi; }
    qreal angle() const { return mAngle; }
    int div() const { return mDiv; }

    void setRo(qreal);
    void setRi(qreal);
    void setAngle(qreal);
    void setDiv(int);

signals:
    void roChanged(qreal);
    void riChanged(qreal);
    void angleChanged(qreal);
    void divChanged(int);

private:
    qreal mRo;
    qreal mRi;
    qreal mAngle;
    int mDiv;
    bool mRegenGeometry;
    bool mRegenColor;
    bool mReallocGeometry;
};

#endif // RING_H
